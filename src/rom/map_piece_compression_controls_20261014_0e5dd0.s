.setcpu "65816"
.segment "CODE"
.org $5DD0
map_control_0e5dd0:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
