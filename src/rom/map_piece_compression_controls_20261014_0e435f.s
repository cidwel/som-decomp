.setcpu "65816"
.segment "CODE"
.org $435F
map_control_0e435f:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
