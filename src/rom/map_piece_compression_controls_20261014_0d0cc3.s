.setcpu "65816"
.segment "CODE"
.org $0CC3
map_control_0d0cc3:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
