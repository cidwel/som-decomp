.setcpu "65816"
.segment "CODE"
.org $0B6C
map_control_0e0b6c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
