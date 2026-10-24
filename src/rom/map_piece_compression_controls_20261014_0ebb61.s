.setcpu "65816"
.segment "CODE"
.org $BB61
map_control_0ebb61:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
