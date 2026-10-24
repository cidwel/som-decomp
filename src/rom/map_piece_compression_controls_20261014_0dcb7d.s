.setcpu "65816"
.segment "CODE"
.org $CB7D
map_control_0dcb7d:
    .byte $E8 ; backreference distance high bits
    .byte $2A ; distance low bit/count
