.setcpu "65816"
.segment "CODE"
.org $3CE2
map_control_0c3ce2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
