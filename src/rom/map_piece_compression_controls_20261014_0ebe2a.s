.setcpu "65816"
.segment "CODE"
.org $BE2A
map_control_0ebe2a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
