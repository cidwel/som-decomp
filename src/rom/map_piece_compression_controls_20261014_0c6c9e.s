.setcpu "65816"
.segment "CODE"
.org $6C9E
map_control_0c6c9e:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
