.setcpu "65816"
.segment "CODE"
.org $4435
map_control_0c4435:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
