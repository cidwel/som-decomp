.setcpu "65816"
.segment "CODE"
.org $5E98
map_control_0e5e98:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
