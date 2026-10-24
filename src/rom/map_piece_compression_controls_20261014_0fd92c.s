.setcpu "65816"
.segment "CODE"
.org $D92C
map_control_0fd92c:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
