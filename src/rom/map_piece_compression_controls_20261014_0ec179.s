.setcpu "65816"
.segment "CODE"
.org $C179
map_control_0ec179:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
