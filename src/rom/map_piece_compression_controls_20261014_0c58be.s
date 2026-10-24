.setcpu "65816"
.segment "CODE"
.org $58BE
map_control_0c58be:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
