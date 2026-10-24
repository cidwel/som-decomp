.setcpu "65816"
.segment "CODE"
.org $B08C
map_control_0fb08c:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
