.setcpu "65816"
.segment "CODE"
.org $69E5
map_control_0c69e5:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
