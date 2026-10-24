.setcpu "65816"
.segment "CODE"
.org $DD08
map_control_0fdd08:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
