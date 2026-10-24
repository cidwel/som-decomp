.setcpu "65816"
.segment "CODE"
.org $7879
map_control_0c7879:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
