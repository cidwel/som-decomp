.setcpu "65816"
.segment "CODE"
.org $3C8C
map_control_0d3c8c:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E4 ; previous-row copy count
