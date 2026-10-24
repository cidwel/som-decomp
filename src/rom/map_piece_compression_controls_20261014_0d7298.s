.setcpu "65816"
.segment "CODE"
.org $7298
map_control_0d7298:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
