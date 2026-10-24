.setcpu "65816"
.segment "CODE"
.org $5EF3
map_control_0e5ef3:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
