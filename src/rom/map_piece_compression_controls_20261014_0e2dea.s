.setcpu "65816"
.segment "CODE"
.org $2DEA
map_control_0e2dea:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
