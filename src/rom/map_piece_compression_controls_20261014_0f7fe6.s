.setcpu "65816"
.segment "CODE"
.org $7FE6
map_control_0f7fe6:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
