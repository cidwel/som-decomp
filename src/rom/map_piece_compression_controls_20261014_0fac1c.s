.setcpu "65816"
.segment "CODE"
.org $AC1C
map_control_0fac1c:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
