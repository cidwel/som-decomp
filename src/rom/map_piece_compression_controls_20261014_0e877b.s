.setcpu "65816"
.segment "CODE"
.org $877B
map_control_0e877b:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
