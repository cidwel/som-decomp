.setcpu "65816"
.segment "CODE"
.org $B0BA
map_control_0db0ba:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
