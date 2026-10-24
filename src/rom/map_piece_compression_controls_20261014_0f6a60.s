.setcpu "65816"
.segment "CODE"
.org $6A60
map_control_0f6a60:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
