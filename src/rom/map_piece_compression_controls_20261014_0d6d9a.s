.setcpu "65816"
.segment "CODE"
.org $6D9A
map_control_0d6d9a:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
