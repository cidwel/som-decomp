.setcpu "65816"
.segment "CODE"
.org $9DD6
map_control_0d9dd6:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
