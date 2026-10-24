.setcpu "65816"
.segment "CODE"
.org $1ECC
map_control_0f1ecc:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
