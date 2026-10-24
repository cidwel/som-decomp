.setcpu "65816"
.segment "CODE"
.org $7A79
map_control_0d7a79:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
