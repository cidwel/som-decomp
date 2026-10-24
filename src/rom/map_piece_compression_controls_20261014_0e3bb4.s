.setcpu "65816"
.segment "CODE"
.org $3BB4
map_control_0e3bb4:
    .byte $EC ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
