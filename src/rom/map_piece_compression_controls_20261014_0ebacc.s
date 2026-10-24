.setcpu "65816"
.segment "CODE"
.org $BACC
map_control_0ebacc:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
