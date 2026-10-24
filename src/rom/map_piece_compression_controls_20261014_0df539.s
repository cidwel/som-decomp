.setcpu "65816"
.segment "CODE"
.org $F539
map_control_0df539:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
