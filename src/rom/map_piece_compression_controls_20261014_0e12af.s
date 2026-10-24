.setcpu "65816"
.segment "CODE"
.org $12AF
map_control_0e12af:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
