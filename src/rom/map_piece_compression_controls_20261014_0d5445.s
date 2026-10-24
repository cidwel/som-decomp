.setcpu "65816"
.segment "CODE"
.org $5445
map_control_0d5445:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
