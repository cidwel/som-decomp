.setcpu "65816"
.segment "CODE"
.org $387C
map_control_0f387c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
