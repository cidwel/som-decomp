.setcpu "65816"
.segment "CODE"
.org $912B
map_control_0e912b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
