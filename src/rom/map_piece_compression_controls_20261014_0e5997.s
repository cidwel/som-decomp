.setcpu "65816"
.segment "CODE"
.org $5997
map_control_0e5997:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
