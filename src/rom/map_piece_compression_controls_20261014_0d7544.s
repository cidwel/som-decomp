.setcpu "65816"
.segment "CODE"
.org $7544
map_control_0d7544:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
