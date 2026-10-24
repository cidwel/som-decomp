.setcpu "65816"
.segment "CODE"
.org $E9D2
map_control_0de9d2:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
