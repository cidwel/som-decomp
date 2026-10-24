.setcpu "65816"
.segment "CODE"
.org $3A07
map_control_0f3a07:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
