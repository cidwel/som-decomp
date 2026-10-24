.setcpu "65816"
.segment "CODE"
.org $9A84
map_control_0e9a84:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
