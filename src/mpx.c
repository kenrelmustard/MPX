#include "mpx_supt.h"
#include "mpx_r1.h" // Bring in R1 code
void errorDecode( int err);


void main(){
	int error;
	sys_init( MODULE_R1 ); //System initilization 
	error = r1();
	if (error != OK ){
	    errorDecode(error);
	}
	sys_exit(); // MPX System Exit functions
}
void errorDecode(int err){
switch( err ){
		case ERR_SUP_INVDEV:
			printf("Invalid device ID");
			break;
		case ERR_SUP_INVOPC:
			printf("Invalid operation Code");
			break;
		case ERR_SUP_INVPOS:
			printf("Invalid character postition");
			break;
		case ERR_SUP_RDFAIL:
			printf("Read Failed"); // could be sysrec or sys get entry
			break;
		case ERR_SUP_WRFAIL:
			printf("Write Failed");
			break;
		// ERR_SUP_INVMOD Exists in documentation but is not present in support code?
		case ERR_SUP_INVMEM:
			printf("Invalid memory block pointer");
			break;
		case ERR_SUP_FRFAIL:
			printf("Memory Freeing Op Failed");
			break;
		case ERR_SUP_INVDAT:
			printf("Invalid Date");
			break;
		case ERR_SUP_DATNCH:
			printf("Date not properly changed");
			break;
		case ERR_SUP_INVDIR:
			printf("Invalid name or no such directory");
			break;
		case ERR_SUP_DIROPN:
			printf("Error Opening Directory");
			break;
		case ERR_SUP_DIRNOP:
			printf("No directory is open");
			break;
		case ERR_SUP_NOENTR:
			printf("No more entries found");
			break;
		case ERR_SUP_NAMLNG:
			printf("The name was too long for the buffer");
			break;
		case ERR_SUP_DIRCLS:
			printf("Error closing the directory");
			break;
		default:
			printf("Unknown Error Code: %d /n",err);
			break;
		}
}