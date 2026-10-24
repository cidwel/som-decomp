.setcpu "65816"
.segment "CODE"
.org $9724
map_control_0e9724:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
