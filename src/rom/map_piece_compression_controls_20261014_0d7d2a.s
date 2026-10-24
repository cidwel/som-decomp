.setcpu "65816"
.segment "CODE"
.org $7D2A
map_control_0d7d2a:
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
