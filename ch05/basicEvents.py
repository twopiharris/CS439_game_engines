""" basicEvents.py 
    demonstrate essential
    mouse and keyboard events"""
    
import pygame
pygame.init()

def main():

    screen = pygame.display.set_mode((640, 480))
    pygame.display.set_caption("press mouse and keys - look for output in console")
    
    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill(pygame.color.Color("yellow"))
    
    keepGoing = True
    clock = pygame.time.Clock()

    while keepGoing:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                keepGoing = False
            elif event.type == pygame.KEYDOWN:
                keyName = pygame.key.name(event.key)
                print ("key pressed:", keyName)
                if event.key == pygame.K_ESCAPE:
                    keepGoing = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                print ("mouse down:", pygame.mouse.get_pos())
            elif event.type == pygame.MOUSEBUTTONUP:
                print ("mouse up:", pygame.mouse.get_pos())
            
        screen.blit(background, (0, 0))
        pygame.display.flip()
    pygame.quit()
        
if __name__ == "__main__":
    main()