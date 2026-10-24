.setcpu "65816"
.segment "CODE"
.org $964A
map_control_0d964a:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
