.setcpu "65816"
.segment "CODE"
.org $29C4
map_control_0e29c4:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
