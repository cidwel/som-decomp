.setcpu "65816"
.segment "CODE"
.org $5B18
map_control_0e5b18:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
