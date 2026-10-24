.setcpu "65816"
.segment "CODE"
.org $D95C
map_control_0dd95c:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
