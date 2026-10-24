.setcpu "65816"
.segment "CODE"
.org $9DD0
map_control_0e9dd0:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
