.setcpu "65816"
.segment "CODE"
.org $400F
map_control_0d400f:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
