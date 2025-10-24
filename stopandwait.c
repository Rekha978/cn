#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sender(inttotalFrames);
void receiver(int frame);
void main()
{
inttotalFrames;
	printf("=== Stop and wait protocol Simulation ===\n);
	printf("Enter total no.of frames to send: ");
	scanf("%d", &totalFrames);
	sender(totalFrames);
}
void sender(inttotalFrames)
{
	inti,ack,choice;
	srand(time(NULL));
	for(i=1;i<=totalFrames;i++)
	{
		printf("\nSender: Sending Frame %d",i);
		printf("\nReceiver: Do you want to ACK Frame %d? (1=Yes,0=No): ",i);
		scanf("%d",&choice);
		if(choice==1)
		{
receiver(i);
			printf("Sender: ACK %d received \n",i);
		}
		else
		{
			printf("Sender: ACK %d lost.Retransmitting...\n",i);
i--
		}
	}
	printf("\nAll %d frames sent suceesfully!\n",totalFrames);
}
void receiver(int frame)
{
	printf("Reciever: Frame %d received.Sending ACK %d...\n,frame,frame);
}
