.setcpu "65816"
.segment "CODE"
.org $9B39
map_control_0e9b39:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
