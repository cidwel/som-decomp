.setcpu "65816"
.segment "CODE"
.org $11A6
map_control_0f11a6:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
