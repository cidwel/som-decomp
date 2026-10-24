.setcpu "65816"
.segment "CODE"
.org $BEAB
map_control_0ebeab:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
