""" customFont.py
    use of a customized font """

import pygame
pygame.init()

def main():
    screen = pygame.display.set_mode((640, 480))
    pygame.display.set_caption("display some text")
    
    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill((0, 0, 0))
    
    myFont = pygame.font.Font("GringoNights.ttf", 40)
    label = myFont.render("Python in the Wild West", 1, (255, 255, 0))
    
    clock = pygame.time.Clock()
    keepGoing = True
    while keepGoing:
        clock.tick(30)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                keepGoing = False
        
        screen.blit(background, (0, 0))
        screen.blit(label, (100, 100))
        
        pygame.display.flip()
    pygame.quit()

if __name__ == "__main__":
    main()    
