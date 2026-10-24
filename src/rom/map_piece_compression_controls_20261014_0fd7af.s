.setcpu "65816"
.segment "CODE"
.org $D7AF
map_control_0fd7af:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
