.setcpu "65816"
.segment "CODE"
.org $EECE
map_control_0feece:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
