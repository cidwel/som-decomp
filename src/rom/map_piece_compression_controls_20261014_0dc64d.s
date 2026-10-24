.setcpu "65816"
.segment "CODE"
.org $C64D
map_control_0dc64d:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
