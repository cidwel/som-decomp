.setcpu "65816"
.segment "CODE"
.org $7F3C
map_control_0d7f3c:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
