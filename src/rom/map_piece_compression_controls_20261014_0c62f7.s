.setcpu "65816"
.segment "CODE"
.org $62F7
map_control_0c62f7:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
