.setcpu "65816"
.segment "CODE"
.org $9D4C
map_control_0f9d4c:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
