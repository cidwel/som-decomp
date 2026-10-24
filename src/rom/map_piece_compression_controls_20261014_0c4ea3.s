.setcpu "65816"
.segment "CODE"
.org $4EA3
map_control_0c4ea3:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
