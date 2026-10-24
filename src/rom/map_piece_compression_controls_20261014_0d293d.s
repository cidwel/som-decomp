.setcpu "65816"
.segment "CODE"
.org $293D
map_control_0d293d:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
