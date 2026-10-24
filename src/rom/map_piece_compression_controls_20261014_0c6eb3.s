.setcpu "65816"
.segment "CODE"
.org $6EB3
map_control_0c6eb3:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
