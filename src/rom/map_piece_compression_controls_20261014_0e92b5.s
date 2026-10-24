.setcpu "65816"
.segment "CODE"
.org $92B5
map_control_0e92b5:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
