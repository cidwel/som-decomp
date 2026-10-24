.setcpu "65816"
.segment "CODE"
.org $99C2
map_control_0e99c2:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
