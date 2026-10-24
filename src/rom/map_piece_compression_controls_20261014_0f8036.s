.setcpu "65816"
.segment "CODE"
.org $8036
map_control_0f8036:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
