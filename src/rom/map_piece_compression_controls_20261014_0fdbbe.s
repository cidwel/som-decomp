.setcpu "65816"
.segment "CODE"
.org $DBBE
map_control_0fdbbe:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
