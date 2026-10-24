.setcpu "65816"
.segment "CODE"
.org $4AB2
map_control_0d4ab2:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
