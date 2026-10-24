.setcpu "65816"
.segment "CODE"
.org $3EB2
map_control_0e3eb2:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
