.setcpu "65816"
.segment "CODE"
.org $AFFF
map_control_0fafff:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
