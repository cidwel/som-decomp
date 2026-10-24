.setcpu "65816"
.segment "CODE"
.org $08AE
map_control_0f08ae:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
