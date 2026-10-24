.setcpu "65816"
.segment "CODE"
.org $60DD
map_control_0c60dd:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
