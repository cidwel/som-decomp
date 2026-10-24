.setcpu "65816"
.segment "CODE"
.org $B6A6
map_control_0eb6a6:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
