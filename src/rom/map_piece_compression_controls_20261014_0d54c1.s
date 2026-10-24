.setcpu "65816"
.segment "CODE"
.org $54C1
map_control_0d54c1:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
