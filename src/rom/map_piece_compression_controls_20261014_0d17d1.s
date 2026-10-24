.setcpu "65816"
.segment "CODE"
.org $17D1
map_control_0d17d1:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
