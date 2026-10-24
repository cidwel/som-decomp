.setcpu "65816"
.segment "CODE"
.org $6C22
map_control_0f6c22:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
