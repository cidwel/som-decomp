.setcpu "65816"
.segment "CODE"
.org $8D6A
map_control_0e8d6a:
    .byte $D3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
