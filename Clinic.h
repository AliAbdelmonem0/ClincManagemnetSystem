typedef struct node_t node;

struct node_t
{
	u8 name[60];
	u8 age;
	u8 gender[10];
	u32 id;
    node * next;
};


void AddPatient(u8 name[],u32 age,u8 gender[], u32 id);
void EditPatientRecord(u32 id);
void DeleteNode(u32 data);
void TimeReservationForUser() ;
void CancelReservation(u32 ID);
void ViewPatientRecord(u32 id);
void PrintReservations();
void PatientReservation (u32 id);
