.setcpu "65816"
.segment "CODE"
.org $6D85
map_control_0d6d85:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
