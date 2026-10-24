.setcpu "65816"
.segment "CODE"
.org $51F3
map_control_0f51f3:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
