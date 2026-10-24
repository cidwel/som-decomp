.setcpu "65816"
.segment "CODE"
.org $75AE
map_control_0d75ae:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
