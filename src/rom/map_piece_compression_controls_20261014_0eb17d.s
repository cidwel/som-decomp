.setcpu "65816"
.segment "CODE"
.org $B17D
map_control_0eb17d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
