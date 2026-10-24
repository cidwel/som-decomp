.setcpu "65816"
.segment "CODE"
.org $5329
map_control_0f5329:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
