.setcpu "65816"
.segment "CODE"
.org $EF93
map_control_0fef93:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
