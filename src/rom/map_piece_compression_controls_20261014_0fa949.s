.setcpu "65816"
.segment "CODE"
.org $A949
map_control_0fa949:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
