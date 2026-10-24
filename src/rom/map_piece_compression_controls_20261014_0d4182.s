.setcpu "65816"
.segment "CODE"
.org $4182
map_control_0d4182:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
