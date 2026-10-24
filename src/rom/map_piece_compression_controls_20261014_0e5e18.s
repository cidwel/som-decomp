.setcpu "65816"
.segment "CODE"
.org $5E18
map_control_0e5e18:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
