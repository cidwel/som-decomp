.setcpu "65816"
.segment "CODE"
.org $3844
map_control_0c3844:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
