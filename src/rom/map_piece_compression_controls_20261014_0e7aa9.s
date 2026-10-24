.setcpu "65816"
.segment "CODE"
.org $7AA9
map_control_0e7aa9:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
