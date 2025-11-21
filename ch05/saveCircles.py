""" saveCircles.py 
    builds a simple pattern of circles and 
    saves the result as "circles.bmp" """
    
import pygame
pygame.init()

def main():
    #no display!  
    background = pygame.Surface((640, 480))
    background.fill((0, 0, 0))

    for i in range(1, 320, 3):
        pygame.draw.circle(background, (0xFF, 0x00, 0x00), (i, i), i, 1)
        pygame.draw.circle(background, (0x00, 0x00, 0xFF), (640 - i, i), i, 1)
        pygame.draw.circle(background, (0x00, 0x00, 0xFF), (i, 480 - i), i, 1)
        pygame.draw.circle(background, (0xFF, 0x00, 0x00), (640 - i, 480 - i), i, 1)
        pygame.draw.circle(background, (0xFF, 0xFF, 0xFF), (320, 240), i, 1)
    
    #save the background 
    pygame.image.save(background, "circles.bmp")
    
    #no need for a main loop here! 
    print ("look in current directory for circles.bmp")
    pygame.quit()
        
if __name__ == "__main__":
    main()
