.setcpu "65816"
.segment "CODE"
.org $ACFC
map_control_0eacfc:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
