.setcpu "65816"
.segment "CODE"
.org $6590
map_control_0e6590:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
