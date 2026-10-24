.setcpu "65816"
.segment "CODE"
.org $311C
map_control_0c311c:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
