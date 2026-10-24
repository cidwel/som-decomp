.setcpu "65816"
.segment "CODE"
.org $7075
map_control_0f7075:
    .byte $E9 ; backreference distance high bits
    .byte $07 ; distance low bit/count
