""" lines.py 
    combine event handling and 
    drawing commands to build
    a prototype drawing program """

import pygame
pygame.init()

def main():
    screen = pygame.display.set_mode((640, 480))
    pygame.display.set_caption("Draw lines with the mouse")
    
    background = pygame.Surface(screen.get_size())
    background.fill((255, 255,255))
    
    clock = pygame.time.Clock()
    keepGoing = True
    preview = False
    lineStart = (0, 0)
    lineEnd = (0, 0)
    
    while(keepGoing):
        clock.tick(30)
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                keepGoing = False
            elif event.type == pygame.MOUSEBUTTONDOWN:
                lineStart = pygame.mouse.get_pos()
                preview = True
            elif event.type == pygame.MOUSEBUTTONUP:
                lineEnd = pygame.mouse.get_pos()
                pygame.draw.line(background, (0, 0, 0), lineStart, lineEnd, 3)
                preview = False
            elif event.type == pygame.MOUSEMOTION:
                lineEnd = pygame.mouse.get_pos()
                
            
        screen.blit(background, (0, 0))
        if preview:
            pygame.draw.line(screen, (100, 100, 100), lineStart, lineEnd, 1)

        pygame.display.flip()
    pygame.quit()
    
if __name__ == "__main__":
    main()

    