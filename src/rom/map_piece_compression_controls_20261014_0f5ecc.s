.setcpu "65816"
.segment "CODE"
.org $5ECC
map_control_0f5ecc:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $D2 ; same-value copy count/distance
