#include "display.h"

// #define DISP_OUT UART_3
// #define MAX_MSG_LEN 32
// #define MAX_ARG_LEN 16
// // Assignment commands have only 1 arg, an operator, and an attribute
// #define isAssignCmd(cmd) (cmd.compOrCmd != NULL && cmd.op != NULL && cmd.attr != NULL && cmd.numArgs == 1)
// // Operational commands have no attribute and no operator, just a command and >= 0 arguments
// #define isOpCmd(cmd) (cmd.op == NULL && cmd.attr == NULL)

// static const char *TERMINATOR = "\xff\xff\xff";

// DisplayError_t Display_Init(){
// 	BSP_UART_Init(DISP_OUT);
    
// 	return Display_Reset();
// }

// DisplayError_t Display_Send(DisplayCmd_t cmd){
// 	char msgArgs[MAX_MSG_LEN];
// 	if (isAssignCmd(cmd)){
// 		if (cmd.argTypes[0] == INT_ARG){
// 			sprintf(msgArgs, "%d", (int)cmd.args[0].num);
// 		}
// 		else{
// 			if (cmd.args[0].str == NULL){return DISPLAY_ERR_PARSE;}
// 			sprintf(msgArgs, "%s", cmd.args[0].str);
// 		}

// 		BSP_UART_Write(DISP_OUT, cmd.compOrCmd, strlen(cmd.compOrCmd));
// 		BSP_UART_Write(DISP_OUT, ".", 1);
// 		BSP_UART_Write(DISP_OUT, cmd.attr, strlen(cmd.attr));
// 		BSP_UART_Write(DISP_OUT, cmd.op, strlen(cmd.op));
// 	}
// 	else if (isOpCmd(cmd)){
// 		msgArgs[0] = ' '; // No args
// 		msgArgs[1] = '\0';
// 		if (cmd.numArgs > MAX_ARGS){return DISPLAY_ERR_OTHER;}
// 		if (cmd.numArgs >= 1){ // If there are arguments
// 			for (int i = 0; i < cmd.numArgs; i++){
// 				char arg[MAX_ARG_LEN];
// 				if (cmd.argTypes[i] == INT_ARG){
// 					sprintf(arg, "%d", (int)cmd.args[i].num);
// 				}
// 				else{
// 					sprintf(arg, "%s", cmd.args[i].str);
// 				}

// 				strcat(msgArgs, arg);

// 				if (i < cmd.numArgs - 1){ // delimiter
// 					strcat(msgArgs, ",");
// 				}
// 			}
// 		}
// 		BSP_UART_Write(DISP_OUT, cmd.compOrCmd, strlen(cmd.compOrCmd));
// 	}
// 	else{ // Error parsing command struct
// 		return DISPLAY_ERR_PARSE;
// 	}

// 	if (cmd.numArgs >= 1){ // If there are arguments
// 		BSP_UART_Write(DISP_OUT, msgArgs, strlen(msgArgs));
// 	}

// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR));

// 	return DISPLAY_ERR_NONE;
// }

// DisplayError_t Display_Reset(){
// 	DisplayCmd_t restCmd = {
// 		.compOrCmd = "rest",
// 		.attr = NULL,
// 		.op = NULL,
// 		.numArgs = 0};

// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR)); // Terminates any in progress command

// 	return Display_Send(restCmd);
// }

// DisplayError_t Display_Error(){

// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR)); // Terminates any in progress command

// 	char faultPage[7] = "page 2";
// 	BSP_UART_Write(DISP_OUT, faultPage, strlen(faultPage));
// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR));

//     char setFaultCode[20];
    
//     sprintf(setFaultCode, "%s%d", "oserr.val=", (uint16_t)Error_OS);
//     BSP_UART_Write(DISP_OUT, setFaultCode, strlen(setFaultCode));
//     memset(setFaultCode, 0, strlen(setFaultCode) * sizeof(char));

//     sprintf(setFaultCode, "%s%d", "rccerr.val=", (uint16_t)Error_ReadCarCAN);
//     BSP_UART_Write(DISP_OUT, setFaultCode, strlen(setFaultCode));
//     memset(setFaultCode, 0, strlen(setFaultCode) * sizeof(char));

//     sprintf(setFaultCode, "%s%d", "merr.val=", (uint16_t)Error_ReadTritium);
//     BSP_UART_Write(DISP_OUT, setFaultCode, strlen(setFaultCode));
//     memset(setFaultCode, 0, strlen(setFaultCode) * sizeof(char));

//     sprintf(setFaultCode, "%s%d", "disperr.val=", (uint16_t)Error_UpdateDisplay);
//     BSP_UART_Write(DISP_OUT, setFaultCode, strlen(setFaultCode));
//     memset(setFaultCode, 0, strlen(setFaultCode) * sizeof(char));
	
	
// 	// BSP_UART_Write(DISP_OUT, setFaultCode, strlen(setFaultCode));
// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR));

// 	return DISPLAY_ERR_NONE;
// }

// DisplayError_t Display_Evac(uint8_t SOC_percent, uint32_t supp_mv){
// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR)); // Terminates any in progress command

// 	char evacPage[7] = "page 3";
// 	BSP_UART_Write(DISP_OUT, evacPage, strlen(evacPage));
// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR));

// 	char soc[13];
// 	sprintf(soc, "%s%d", "soc.val=", (int)SOC_percent);
// 	BSP_UART_Write(DISP_OUT, soc, strlen(soc));
// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR));

// 	char supp[18];
// 	sprintf(supp, "%s%d", "supp.val=", (int)supp_mv);
// 	BSP_UART_Write(DISP_OUT, supp, strlen(supp));
// 	BSP_UART_Write(DISP_OUT, (char *)TERMINATOR, strlen(TERMINATOR));

// 	return DISPLAY_ERR_NONE;
// }