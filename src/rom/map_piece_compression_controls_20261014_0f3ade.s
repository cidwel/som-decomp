.setcpu "65816"
.segment "CODE"
.org $3ADE
map_control_0f3ade:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
