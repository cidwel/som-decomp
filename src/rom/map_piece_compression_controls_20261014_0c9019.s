.setcpu "65816"
.segment "CODE"
.org $9019
map_control_0c9019:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
