.setcpu "65816"
.segment "CODE"
.org $5E12
map_control_0e5e12:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
