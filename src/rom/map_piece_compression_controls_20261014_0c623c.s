.setcpu "65816"
.segment "CODE"
.org $623C
map_control_0c623c:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
