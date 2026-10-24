.setcpu "65816"
.segment "CODE"
.org $A6B8
map_control_0fa6b8:
    .byte $C9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
