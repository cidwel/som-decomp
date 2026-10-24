.setcpu "65816"
.segment "CODE"
.org $7D50
map_control_0f7d50:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
