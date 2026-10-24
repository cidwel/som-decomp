.setcpu "65816"
.segment "CODE"
.org $9EA1
map_control_0d9ea1:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
