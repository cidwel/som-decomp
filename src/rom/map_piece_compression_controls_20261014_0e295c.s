.setcpu "65816"
.segment "CODE"
.org $295C
map_control_0e295c:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
