.setcpu "65816"
.segment "CODE"
.org $24F6
map_control_0d24f6:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
