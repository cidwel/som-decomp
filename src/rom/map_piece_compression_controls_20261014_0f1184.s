.setcpu "65816"
.segment "CODE"
.org $1184
map_control_0f1184:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
