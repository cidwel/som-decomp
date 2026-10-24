.setcpu "65816"
.segment "CODE"
.org $2AC5
map_control_0c2ac5:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
