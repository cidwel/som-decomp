.setcpu "65816"
.segment "CODE"
.org $4167
map_control_0d4167:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
