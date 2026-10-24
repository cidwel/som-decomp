.setcpu "65816"
.segment "CODE"
.org $D0FC
map_control_0fd0fc:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
