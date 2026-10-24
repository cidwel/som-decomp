.setcpu "65816"
.segment "CODE"
.org $1263
map_control_0f1263:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
