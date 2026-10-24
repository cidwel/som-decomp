.setcpu "65816"
.segment "CODE"
.org $BB81
map_control_0fbb81:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
