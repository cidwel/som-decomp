.setcpu "65816"
.segment "CODE"
.org $5221
map_control_0f5221:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
