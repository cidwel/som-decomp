.setcpu "65816"
.segment "CODE"
.org $43EA
map_control_0d43ea:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
