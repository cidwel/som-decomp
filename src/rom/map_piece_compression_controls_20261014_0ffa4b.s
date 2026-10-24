.setcpu "65816"
.segment "CODE"
.org $FA4B
map_control_0ffa4b:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
