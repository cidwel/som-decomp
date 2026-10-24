.setcpu "65816"
.segment "CODE"
.org $98F0
map_control_0e98f0:
    .byte $E8 ; backreference distance high bits
    .byte $B0 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
