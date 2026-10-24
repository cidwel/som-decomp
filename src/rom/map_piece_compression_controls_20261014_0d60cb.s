.setcpu "65816"
.segment "CODE"
.org $60CB
map_control_0d60cb:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
