.setcpu "65816"
.segment "CODE"
.org $D861
map_control_0fd861:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
