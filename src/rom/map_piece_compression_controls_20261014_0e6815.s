.setcpu "65816"
.segment "CODE"
.org $6815
map_control_0e6815:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
