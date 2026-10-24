.setcpu "65816"
.segment "CODE"
.org $AAA1
map_control_0eaaa1:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
