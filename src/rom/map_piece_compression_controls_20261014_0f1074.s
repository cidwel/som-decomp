.setcpu "65816"
.segment "CODE"
.org $1074
map_control_0f1074:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
