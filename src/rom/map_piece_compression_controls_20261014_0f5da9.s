.setcpu "65816"
.segment "CODE"
.org $5DA9
map_control_0f5da9:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
