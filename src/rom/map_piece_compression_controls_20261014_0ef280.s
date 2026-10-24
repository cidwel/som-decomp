.setcpu "65816"
.segment "CODE"
.org $F280
map_control_0ef280:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
