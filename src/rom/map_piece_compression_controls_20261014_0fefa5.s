.setcpu "65816"
.segment "CODE"
.org $EFA5
map_control_0fefa5:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
