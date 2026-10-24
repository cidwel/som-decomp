.setcpu "65816"
.segment "CODE"
.org $BBBA
map_control_0ebbba:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
