.setcpu "65816"
.segment "CODE"
.org $6A79
map_control_0c6a79:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
