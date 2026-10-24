.setcpu "65816"
.segment "CODE"
.org $DD76
map_control_0fdd76:
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
