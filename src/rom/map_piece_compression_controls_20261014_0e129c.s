.setcpu "65816"
.segment "CODE"
.org $129C
map_control_0e129c:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2D ; distance low bit/count
