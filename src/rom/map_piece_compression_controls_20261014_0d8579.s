.setcpu "65816"
.segment "CODE"
.org $8579
map_control_0d8579:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
