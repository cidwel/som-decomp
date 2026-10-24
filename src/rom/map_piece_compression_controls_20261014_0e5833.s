.setcpu "65816"
.segment "CODE"
.org $5833
map_control_0e5833:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
