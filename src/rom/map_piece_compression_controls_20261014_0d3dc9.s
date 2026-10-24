.setcpu "65816"
.segment "CODE"
.org $3DC9
map_control_0d3dc9:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
