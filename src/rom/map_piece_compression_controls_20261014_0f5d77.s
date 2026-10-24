.setcpu "65816"
.segment "CODE"
.org $5D77
map_control_0f5d77:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
