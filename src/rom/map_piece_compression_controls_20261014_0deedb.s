.setcpu "65816"
.segment "CODE"
.org $EEDB
map_control_0deedb:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
