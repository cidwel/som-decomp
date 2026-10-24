.setcpu "65816"
.segment "CODE"
.org $DCEF
map_control_0ddcef:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
