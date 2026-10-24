.setcpu "65816"
.segment "CODE"
.org $EAD8
map_control_0eead8:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7E ; distance low bit/count
