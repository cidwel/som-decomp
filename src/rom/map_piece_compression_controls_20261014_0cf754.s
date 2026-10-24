.setcpu "65816"
.segment "CODE"
.org $F754
map_control_0cf754:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
