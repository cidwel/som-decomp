.setcpu "65816"
.segment "CODE"
.org $110E
map_control_0e110e:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $66 ; distance low bit/count
