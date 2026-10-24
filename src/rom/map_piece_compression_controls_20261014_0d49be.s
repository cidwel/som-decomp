.setcpu "65816"
.segment "CODE"
.org $49BE
map_control_0d49be:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
