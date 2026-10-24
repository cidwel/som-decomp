.setcpu "65816"
.segment "CODE"
.org $877C
map_control_0c877c:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
