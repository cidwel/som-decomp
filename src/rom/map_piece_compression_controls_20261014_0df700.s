.setcpu "65816"
.segment "CODE"
.org $F700
map_control_0df700:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
