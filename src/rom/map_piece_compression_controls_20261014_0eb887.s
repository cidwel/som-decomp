.setcpu "65816"
.segment "CODE"
.org $B887
map_control_0eb887:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $9E ; distance low bit/count
