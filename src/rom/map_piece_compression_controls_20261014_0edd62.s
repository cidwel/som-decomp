.setcpu "65816"
.segment "CODE"
.org $DD62
map_control_0edd62:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
