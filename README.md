Hi!

Welcome to the ASCII video converter repository. This program converts videos to ASCII art. There are a few things to note before you run this program.

1. You will need to link open cv to your project as it's not included here.
2. The video requires a full screen terminal to be seen properly due to the amount of characters being printed to the screen.
3. I added a make file for those of you who wish to run this in linux (opencv is in the make file but you will still need to add open cv to your system).
4. There is no video provided (to save space in github) so you will need to save one to the same folder as Main.cpp
5. Rename the video_path variable located at the start of the main function to match the video you added.
6. This program has not been tested in Windows, only Linux, and it works great.

If the program starts flickering, it's because your terminal has no room for the characters and it keeps scrolling. If you need to, mess with the FRAMEW and FRAMEH macros at the top of the program to change the ASCII art width and height, but do your best to keep it near 20:9 or 21:9. 16:9 videos work best, but you should make it wider since to account for line spacing being more than letter spacing.

***FRAMERATE****

The frame rate is controlled at the bottom of the main function using chrono milliseconds:

std::this_thread::sleep_for(std::chrono::milliseconds(33));

Right now, it's set for 30 fps because 1 second divided by 30 is 0.033 seconds or 33 milliseconds. If you upload a video with a higher frame rate, simply take 1000 divided by the frame rate and you will have your milliseconds. Put that number in the brackets in the line of code rounding to the nearest whole number. If you don't know the frame rate, you can comment out the following line in the 'if' statement in the main function temporarily:

ASCIIconvert(resizedFrame);

Then you'll be able to see the frame rate and frame count displayed in the terminal.

Thank you for checking out my repository and enjoy.
