.setcpu "65816"
.segment "CODE"
.org $383A
map_control_0f383a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
