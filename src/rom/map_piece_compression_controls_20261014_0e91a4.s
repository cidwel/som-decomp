.setcpu "65816"
.segment "CODE"
.org $91A4
map_control_0e91a4:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
