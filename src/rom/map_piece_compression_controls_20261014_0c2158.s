.setcpu "65816"
.segment "CODE"
.org $2158
map_control_0c2158:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
