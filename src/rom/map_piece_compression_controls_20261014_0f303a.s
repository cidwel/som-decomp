.setcpu "65816"
.segment "CODE"
.org $303A
map_control_0f303a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
