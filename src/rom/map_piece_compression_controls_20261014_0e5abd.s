.setcpu "65816"
.segment "CODE"
.org $5ABD
map_control_0e5abd:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
