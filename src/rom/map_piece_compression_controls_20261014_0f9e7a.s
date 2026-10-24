.setcpu "65816"
.segment "CODE"
.org $9E7A
map_control_0f9e7a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
