.setcpu "65816"
.segment "CODE"
.org $860C
map_control_0f860c:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
