.setcpu "65816"
.segment "CODE"
.org $55DB
map_control_0f55db:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
