.setcpu "65816"
.segment "CODE"
.org $F1FE
map_control_0ff1fe:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
