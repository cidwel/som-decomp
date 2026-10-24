.setcpu "65816"
.segment "CODE"
.org $B7F7
map_control_0eb7f7:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
