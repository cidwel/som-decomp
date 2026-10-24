.setcpu "65816"
.segment "CODE"
.org $E9DD
map_control_0de9dd:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
