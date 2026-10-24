.setcpu "65816"
.segment "CODE"
.org $CF8A
map_control_0ecf8a:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
