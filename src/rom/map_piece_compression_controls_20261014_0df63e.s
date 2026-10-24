.setcpu "65816"
.segment "CODE"
.org $F63E
map_control_0df63e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
