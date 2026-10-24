.setcpu "65816"
.segment "CODE"
.org $99BE
map_control_0e99be:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
