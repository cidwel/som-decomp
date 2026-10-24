.setcpu "65816"
.segment "CODE"
.org $CD28
map_control_0ecd28:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
