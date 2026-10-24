.setcpu "65816"
.segment "CODE"
.org $17D6
map_control_0f17d6:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
