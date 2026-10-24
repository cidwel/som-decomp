.setcpu "65816"
.segment "CODE"
.org $5763
map_control_0f5763:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
