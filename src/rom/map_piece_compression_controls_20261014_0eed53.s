.setcpu "65816"
.segment "CODE"
.org $ED53
map_control_0eed53:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
