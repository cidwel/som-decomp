.setcpu "65816"
.segment "CODE"
.org $527C
map_control_0c527c:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
