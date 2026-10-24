.setcpu "65816"
.segment "CODE"
.org $88DB
map_control_0c88db:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
