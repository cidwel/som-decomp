.setcpu "65816"
.segment "CODE"
.org $EF91
map_control_0eef91:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
