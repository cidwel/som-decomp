.setcpu "65816"
.segment "CODE"
.org $6963
map_control_0e6963:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
