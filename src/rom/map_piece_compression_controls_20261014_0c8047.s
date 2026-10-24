.setcpu "65816"
.segment "CODE"
.org $8047
map_control_0c8047:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
