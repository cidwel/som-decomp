.setcpu "65816"
.segment "CODE"
.org $FBEA
map_control_0ffbea:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
