.setcpu "65816"
.segment "CODE"
.org $7DED
map_control_0e7ded:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
