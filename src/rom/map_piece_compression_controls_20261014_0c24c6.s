.setcpu "65816"
.segment "CODE"
.org $24C6
map_control_0c24c6:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
