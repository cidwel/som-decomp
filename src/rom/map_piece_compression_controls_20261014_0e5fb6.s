.setcpu "65816"
.segment "CODE"
.org $5FB6
map_control_0e5fb6:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
