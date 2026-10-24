.setcpu "65816"
.segment "CODE"
.org $E993
map_control_0de993:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
