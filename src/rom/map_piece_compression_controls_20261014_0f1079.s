.setcpu "65816"
.segment "CODE"
.org $1079
map_control_0f1079:
    .byte $EE ; backreference distance high bits
    .byte $99 ; distance low bit/count
