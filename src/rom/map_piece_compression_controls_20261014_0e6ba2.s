.setcpu "65816"
.segment "CODE"
.org $6BA2
map_control_0e6ba2:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
