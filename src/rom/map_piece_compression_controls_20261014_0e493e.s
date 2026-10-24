.setcpu "65816"
.segment "CODE"
.org $493E
map_control_0e493e:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
