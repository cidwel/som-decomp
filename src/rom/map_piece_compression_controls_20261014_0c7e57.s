.setcpu "65816"
.segment "CODE"
.org $7E57
map_control_0c7e57:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
