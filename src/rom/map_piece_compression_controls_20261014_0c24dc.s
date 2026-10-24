.setcpu "65816"
.segment "CODE"
.org $24DC
map_control_0c24dc:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
