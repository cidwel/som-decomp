.setcpu "65816"
.segment "CODE"
.org $C139
map_control_0fc139:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
