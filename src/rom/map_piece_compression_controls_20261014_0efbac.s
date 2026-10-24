.setcpu "65816"
.segment "CODE"
.org $FBAC
map_control_0efbac:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
