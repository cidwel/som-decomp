.setcpu "65816"
.segment "CODE"
.org $51DE
map_control_0e51de:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
