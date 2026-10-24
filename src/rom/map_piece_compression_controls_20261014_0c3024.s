.setcpu "65816"
.segment "CODE"
.org $3024
map_control_0c3024:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
