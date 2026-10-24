.setcpu "65816"
.segment "CODE"
.org $8455
map_control_0c8455:
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
