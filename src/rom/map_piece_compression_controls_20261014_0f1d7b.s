.setcpu "65816"
.segment "CODE"
.org $1D7B
map_control_0f1d7b:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $DA ; same-value copy count/distance
