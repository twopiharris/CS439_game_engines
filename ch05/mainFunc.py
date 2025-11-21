""" mainFunc.py 
    illustrate using the main function
    """
#I - Import and init - still in global scope    
import pygame
pygame.init()

def main():
    #D - Display now part of main function
    screen = pygame.display.set_mode((640, 480))
    pygame.display.set_caption("Now I'm using a main function")
    
    #E - Entities part of main function
    background = pygame.Surface(screen.get_size())
    background.fill((0, 255, 255))
    
    square = pygame.Surface((25, 25))
    square.fill((255, 0, 0))
    
    #Action also part of main function
    clock = pygame.time.Clock()
    keepGoing = True
    while keepGoing:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                keepGoing = False
                
        screen.blit(background, (0, 0))
        screen.blit(square, (300, 200))
        
        pygame.display.flip()
    pygame.quit()

#Run main if this is the primary program        
if __name__ == "__main__":
    main()
