.setcpu "65816"
.segment "CODE"
.org $4B69
map_control_0c4b69:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
