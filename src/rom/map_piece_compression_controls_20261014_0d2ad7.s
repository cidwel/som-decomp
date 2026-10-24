.setcpu "65816"
.segment "CODE"
.org $2AD7
map_control_0d2ad7:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
