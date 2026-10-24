.setcpu "65816"
.segment "CODE"
.org $7622
map_control_0d7622:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
