#!/usr/bin/python3
# -*- coding: UTF-8 -*-

# Play alert sound for top_layer.c

import pygame,time
pygame.mixer.init()
#pygame.mixer.music.load("./media/lose1.wav")
pygame.mixer.music.load("./media/add_score.wav")
pygame.mixer.music.play()
time.sleep(1)
pygame.mixer.music.stop()