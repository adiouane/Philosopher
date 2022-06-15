# Philosopher
Philosophers 


Project Introduction

    (Dining philosophers problem)is a problem created by Edsger Wybe Dijkstra in 1965 to explain the deadlock state of an operating system,
     which is traditionally commonly introduced in lectures on operating systems.

<p align="center">
  <img src="https://velog.velcdn.com/images%2Fdogfootbirdfoot%2Fpost%2F126372e4-5c99-4115-aff4-4854d2758c17%2Fphilosophers.png" width="350" title="hover text">
</p>

For example, (n) philosophers are sitting at the round table and eating. A fork is placed between the philosophers, and the philosophers eat through the following process.

The philosopher repeats three actions:
                                        eating ➔ sleeping ➔ thinking.
    When eating, both forks should be used.
    If you lift both forks, eat for a certain amount of time.
    When you're done eating, put down your fork.
    Not a single philosopher should die from not eating for a certain period of time.
        
If all the philosophers were hungry and picked up the left forks at the same time,
the right forks would have already been picked up by the philosopher sitting to their right, 
and everyone would forever be unable to hold the right forks. That is, there is no further progress,
and the philosophers are forever on standby. This phenomenon is called deadlock.
Once in a deadlock, philosophers continue to suffer and die of starvation.
The task is to implement a program that solves this problem using (mutex) in mandatory!

reference:


                        https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2
                        
                        https://www.youtube.com/watch?v=FYUi-u7UWgw&t=812s&ab_channel=NesoAcademy
                        
                        https://dkwjdi.tistory.com/247
                        
                        https://worthpreading.tistory.com/90
                        
                        https://www.notion.so/7859c9b6372d472c9675b29ce25d4117
                        
                        https://malbongcode.tistory.com/161
                           
                        https://velog.io/@24siefil/Philosophers-Synchronization
                        
                        https://velog.io/@underlier12/OS-24-%EA%B5%90%EC%B0%A9%EC%83%81%ED%83%9C%EC%99%80-%EA%B8%B0%EC%95%84%EC%83%81%ED%83%9C
