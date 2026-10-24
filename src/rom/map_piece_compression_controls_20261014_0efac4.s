.setcpu "65816"
.segment "CODE"
.org $FAC4
map_control_0efac4:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
