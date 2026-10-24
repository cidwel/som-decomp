.setcpu "65816"
.segment "CODE"
.org $FB32
map_control_0dfb32:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
