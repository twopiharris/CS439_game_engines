""" face.py 
    draw an image on the screen"""
    
import pygame
pygame.init()

def main():
    screen = pygame.display.set_mode((640, 480))
    pygame.display.set_caption("Display an image")
    
    background = pygame.Surface(screen.get_size())
    background = background.convert()
    background.fill((255, 255, 0))
    
    face = pygame.image.load("andy.jpg")
    face = face.convert()
    
    clock = pygame.time.Clock()
    keepGoing = True
    while keepGoing:
        clock.tick(30)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                keepGoing = False
        
        screen.blit(background, (0, 0))
        screen.blit(face, (250, 150))
        
        pygame.display.flip()
    pygame.quit()

if __name__ == "__main__":
    main()
    