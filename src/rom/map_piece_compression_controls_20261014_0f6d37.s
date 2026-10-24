.setcpu "65816"
.segment "CODE"
.org $6D37
map_control_0f6d37:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
