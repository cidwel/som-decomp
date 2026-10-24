.setcpu "65816"
.segment "CODE"
.org $65AE
map_control_0e65ae:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
