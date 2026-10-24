.setcpu "65816"
.segment "CODE"
.org $7621
map_control_0e7621:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
