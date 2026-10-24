.setcpu "65816"
.segment "CODE"
.org $43A6
map_control_0d43a6:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
