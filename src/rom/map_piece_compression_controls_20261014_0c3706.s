.setcpu "65816"
.segment "CODE"
.org $3706
map_control_0c3706:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
