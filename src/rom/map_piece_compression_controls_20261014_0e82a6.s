.setcpu "65816"
.segment "CODE"
.org $82A6
map_control_0e82a6:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
