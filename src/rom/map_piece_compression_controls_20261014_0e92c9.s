.setcpu "65816"
.segment "CODE"
.org $92C9
map_control_0e92c9:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
