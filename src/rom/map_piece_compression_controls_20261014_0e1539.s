.setcpu "65816"
.segment "CODE"
.org $1539
map_control_0e1539:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
