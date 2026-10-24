.setcpu "65816"
.segment "CODE"
.org $446B
map_control_0c446b:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
