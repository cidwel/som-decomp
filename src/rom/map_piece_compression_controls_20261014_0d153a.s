.setcpu "65816"
.segment "CODE"
.org $153A
map_control_0d153a:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
