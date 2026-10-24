.setcpu "65816"
.segment "CODE"
.org $F954
map_control_0df954:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
