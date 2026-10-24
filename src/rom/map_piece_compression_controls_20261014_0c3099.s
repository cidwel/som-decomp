.setcpu "65816"
.segment "CODE"
.org $3099
map_control_0c3099:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
