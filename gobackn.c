#include<stdio.h>
void main()
{
        int total_frames,window_size;
        int sent=0,lost_frame,i;
        printf("Enter total number of frames to send: ");
        scanf("%d",&total_frames);
        printf("Enter window size: ");
        scanf("%d",&window_size);
        printf("\n--- GO-Back-N sliding window protocol simulation---\n\n");
        while(sent < total_frames)
        {
                printf("Sender:sending frames");
                for(i=sent;i<sent+window_size && i<total_frames;i++)
                        printf("%d",i);
                printf("\n");
                printf("Enter the frame number to be lost (or -1 if none lost): ");
                scanf("%d",&lost_frame);
                if(lost_frame>=sent && lost_frame <sent+window_size &&lost_frame<total_frames)

                {
                        printf("Receiver:Frame %d lost! Go back and resend from %d\n\n",lost_frame,lost_frame);
                        sent=lost_frame;
                }
                else
                {
                        int ack=sent +window_size;
                        if(ack>total_frames)
                                ack=total_frames;
                        printf("Receiver:Acknowledged up to frame %d\n\n",ack-1);
                        sent=ack;
                }
        }
        printf("All frames sent successfully using GO-BACK-N!\n");
}
