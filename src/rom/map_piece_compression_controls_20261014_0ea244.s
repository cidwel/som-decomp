.setcpu "65816"
.segment "CODE"
.org $A244
map_control_0ea244:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
