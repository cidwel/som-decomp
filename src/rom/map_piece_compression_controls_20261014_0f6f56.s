.setcpu "65816"
.segment "CODE"
.org $6F56
map_control_0f6f56:
    .byte $E8 ; backreference distance high bits
    .byte $39 ; distance low bit/count
