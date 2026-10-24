.setcpu "65816"
.segment "CODE"
.org $92DE
map_control_0f92de:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
