.setcpu "65816"
.segment "CODE"
.org $1E30
map_control_0c1e30:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
