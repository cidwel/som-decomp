.setcpu "65816"
.segment "CODE"
.org $4241
map_control_0f4241:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
