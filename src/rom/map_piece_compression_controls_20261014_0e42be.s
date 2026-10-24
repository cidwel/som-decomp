.setcpu "65816"
.segment "CODE"
.org $42BE
map_control_0e42be:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
