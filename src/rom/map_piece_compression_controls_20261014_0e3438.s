.setcpu "65816"
.segment "CODE"
.org $3438
map_control_0e3438:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
