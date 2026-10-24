.setcpu "65816"
.segment "CODE"
.org $69DA
map_control_0c69da:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
