.setcpu "65816"
.segment "CODE"
.org $DE33
map_control_0ede33:
    .byte $DA ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
