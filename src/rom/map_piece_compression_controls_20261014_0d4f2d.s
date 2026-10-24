.setcpu "65816"
.segment "CODE"
.org $4F2D
map_control_0d4f2d:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
