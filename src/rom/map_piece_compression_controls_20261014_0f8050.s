.setcpu "65816"
.segment "CODE"
.org $8050
map_control_0f8050:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
