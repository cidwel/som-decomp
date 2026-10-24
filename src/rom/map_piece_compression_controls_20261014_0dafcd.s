.setcpu "65816"
.segment "CODE"
.org $AFCD
map_control_0dafcd:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
