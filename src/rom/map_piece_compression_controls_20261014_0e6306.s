.setcpu "65816"
.segment "CODE"
.org $6306
map_control_0e6306:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
