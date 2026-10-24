.setcpu "65816"
.segment "CODE"
.org $EC20
map_control_0eec20:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
