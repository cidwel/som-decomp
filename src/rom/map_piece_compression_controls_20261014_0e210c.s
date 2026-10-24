.setcpu "65816"
.segment "CODE"
.org $210C
map_control_0e210c:
    .byte $C1 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
