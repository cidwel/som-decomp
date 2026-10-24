.setcpu "65816"
.segment "CODE"
.org $B816
map_control_0db816:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
