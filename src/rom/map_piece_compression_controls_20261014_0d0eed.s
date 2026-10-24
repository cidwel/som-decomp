.setcpu "65816"
.segment "CODE"
.org $0EED
map_control_0d0eed:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
