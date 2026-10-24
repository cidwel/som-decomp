.setcpu "65816"
.segment "CODE"
.org $9B39
map_control_0f9b39:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
