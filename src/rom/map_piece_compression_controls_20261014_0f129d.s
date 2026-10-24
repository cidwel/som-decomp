.setcpu "65816"
.segment "CODE"
.org $129D
map_control_0f129d:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
