.setcpu "65816"
.segment "CODE"
.org $7B15
map_control_0c7b15:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
