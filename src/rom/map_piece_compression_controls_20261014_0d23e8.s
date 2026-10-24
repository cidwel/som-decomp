.setcpu "65816"
.segment "CODE"
.org $23E8
map_control_0d23e8:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
