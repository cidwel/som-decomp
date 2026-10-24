.setcpu "65816"
.segment "CODE"
.org $ADBE
map_control_0fadbe:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
