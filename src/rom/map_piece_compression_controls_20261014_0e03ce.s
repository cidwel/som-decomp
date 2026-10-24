.setcpu "65816"
.segment "CODE"
.org $03CE
map_control_0e03ce:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
