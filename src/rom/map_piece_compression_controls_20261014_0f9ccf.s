.setcpu "65816"
.segment "CODE"
.org $9CCF
map_control_0f9ccf:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
