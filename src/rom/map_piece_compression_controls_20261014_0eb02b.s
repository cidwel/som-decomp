.setcpu "65816"
.segment "CODE"
.org $B02B
map_control_0eb02b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
