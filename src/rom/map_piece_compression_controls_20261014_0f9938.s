.setcpu "65816"
.segment "CODE"
.org $9938
map_control_0f9938:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
