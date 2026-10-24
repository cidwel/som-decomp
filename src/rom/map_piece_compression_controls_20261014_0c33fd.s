.setcpu "65816"
.segment "CODE"
.org $33FD
map_control_0c33fd:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
