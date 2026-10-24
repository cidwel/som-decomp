.setcpu "65816"
.segment "CODE"
.org $A1FE
map_control_0da1fe:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
