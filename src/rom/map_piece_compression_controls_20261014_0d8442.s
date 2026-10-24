.setcpu "65816"
.segment "CODE"
.org $8442
map_control_0d8442:
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
