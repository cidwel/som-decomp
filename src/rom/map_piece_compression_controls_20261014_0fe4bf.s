.setcpu "65816"
.segment "CODE"
.org $E4BF
map_control_0fe4bf:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $74 ; distance low bit/count
