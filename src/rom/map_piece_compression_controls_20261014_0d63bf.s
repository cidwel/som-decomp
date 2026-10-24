.setcpu "65816"
.segment "CODE"
.org $63BF
map_control_0d63bf:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
