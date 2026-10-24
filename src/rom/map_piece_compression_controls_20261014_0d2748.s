.setcpu "65816"
.segment "CODE"
.org $2748
map_control_0d2748:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
