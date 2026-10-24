.setcpu "65816"
.segment "CODE"
.org $7B6A
map_control_0d7b6a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
