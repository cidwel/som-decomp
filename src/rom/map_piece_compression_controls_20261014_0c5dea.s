.setcpu "65816"
.segment "CODE"
.org $5DEA
map_control_0c5dea:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
