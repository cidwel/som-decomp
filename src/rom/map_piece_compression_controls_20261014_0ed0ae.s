.setcpu "65816"
.segment "CODE"
.org $D0AE
map_control_0ed0ae:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
