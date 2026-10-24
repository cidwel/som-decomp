.setcpu "65816"
.segment "CODE"
.org $4947
map_control_0d4947:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
