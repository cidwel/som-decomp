.setcpu "65816"
.segment "CODE"
.org $5EB1
map_control_0f5eb1:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
