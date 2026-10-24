.setcpu "65816"
.segment "CODE"
.org $14BF
map_control_0f14bf:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
