/*
 * scheduler.c
 *
 *  Created on: Dec 8, 2022
 *      Author: duyvt
 */

#include "scheduler.h"

sTasks SCH_Tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task =0;

void SCH_Init(void){

}

void SCH_Add_Task (void (*pFunction)(),
					uint32_t DELAY,
					uint32_t PERIOD){
	DELAY = DELAY/TICK;
	PERIOD = PERIOD/TICK;

	if (current_index_task < SCH_MAX_TASKS){
		SCH_Tasks_G[current_index_task].pTask = pFunction;
		SCH_Tasks_G[current_index_task].Delay = DELAY;
		SCH_Tasks_G[current_index_task].Period = PERIOD;
		SCH_Tasks_G[current_index_task].RunMe =0;

		SCH_Tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
}

void SCH_Update(void){
	for (int i=0; i<current_index_task; i++){
		if (SCH_Tasks_G[i].Delay >0){
			SCH_Tasks_G[i].Delay--;
		}else{
			SCH_Tasks_G[i].Delay = SCH_Tasks_G[i].Period;
			SCH_Tasks_G[i].RunMe++;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for (int i=0; i< current_index_task; i++){
		if (SCH_Tasks_G[i].RunMe >0){
			SCH_Tasks_G[i].RunMe --;
			(*SCH_Tasks_G[i].pTask)();
			if (SCH_Tasks_G[i].Period==0){
				SCH_Delete(i);
			}
		}
	}
}

void SCH_Delete(uint32_t ID){
	if (ID >=current_index_task){
		return;
	}else if(ID == current_index_task-1){
		SCH_Tasks_G[ID].pTask =NULL;
		SCH_Tasks_G[ID].Delay =0;
		SCH_Tasks_G[ID].Period =0;
		SCH_Tasks_G[ID].RunMe =0;

		current_index_task--;
	}else if(0 <= ID && ID < current_index_task-1){
		SCH_Tasks_G[ID].pTask = SCH_Tasks_G[current_index_task].pTask;
		SCH_Tasks_G[ID].Delay = SCH_Tasks_G[current_index_task].Delay;
		SCH_Tasks_G[ID].Period = SCH_Tasks_G[current_index_task].Period;
		SCH_Tasks_G[ID].RunMe = SCH_Tasks_G[current_index_task].RunMe;
		SCH_Tasks_G[ID].TaskID = ID;

		SCH_Tasks_G[current_index_task].pTask =NULL;
		SCH_Tasks_G[current_index_task].Delay =0;
		SCH_Tasks_G[current_index_task].Period =0;
		SCH_Tasks_G[current_index_task].RunMe =0;
		SCH_Tasks_G[current_index_task].TaskID =0;

		current_index_task--;
	}
}
