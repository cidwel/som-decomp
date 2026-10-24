.setcpu "65816"
.segment "CODE"
.org $38CC
map_control_0e38cc:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
