.setcpu "65816"
.segment "CODE"
.org $A230
map_control_0da230:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
