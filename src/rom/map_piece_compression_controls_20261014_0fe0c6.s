.setcpu "65816"
.segment "CODE"
.org $E0C6
map_control_0fe0c6:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
