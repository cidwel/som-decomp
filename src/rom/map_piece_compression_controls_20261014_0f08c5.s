.setcpu "65816"
.segment "CODE"
.org $08C5
map_control_0f08c5:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
