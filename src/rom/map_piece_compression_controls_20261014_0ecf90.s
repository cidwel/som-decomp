.setcpu "65816"
.segment "CODE"
.org $CF90
map_control_0ecf90:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
