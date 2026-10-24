.setcpu "65816"
.segment "CODE"
.org $DF28
map_control_0fdf28:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
