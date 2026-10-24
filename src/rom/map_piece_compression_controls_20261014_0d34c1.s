.setcpu "65816"
.segment "CODE"
.org $34C1
map_control_0d34c1:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
