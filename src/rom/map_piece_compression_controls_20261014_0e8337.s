.setcpu "65816"
.segment "CODE"
.org $8337
map_control_0e8337:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
