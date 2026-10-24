.setcpu "65816"
.segment "CODE"
.org $5C9D
map_control_0e5c9d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
