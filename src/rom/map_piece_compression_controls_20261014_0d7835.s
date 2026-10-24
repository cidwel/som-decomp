.setcpu "65816"
.segment "CODE"
.org $7835
map_control_0d7835:
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
