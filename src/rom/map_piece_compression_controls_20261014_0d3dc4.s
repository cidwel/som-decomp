.setcpu "65816"
.segment "CODE"
.org $3DC4
map_control_0d3dc4:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
