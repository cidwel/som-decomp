.setcpu "65816"
.segment "CODE"
.org $AF39
map_control_0eaf39:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
