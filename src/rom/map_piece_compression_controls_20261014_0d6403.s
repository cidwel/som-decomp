.setcpu "65816"
.segment "CODE"
.org $6403
map_control_0d6403:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
