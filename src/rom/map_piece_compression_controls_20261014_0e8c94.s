.setcpu "65816"
.segment "CODE"
.org $8C94
map_control_0e8c94:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
