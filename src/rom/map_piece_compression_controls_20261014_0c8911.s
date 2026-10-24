.setcpu "65816"
.segment "CODE"
.org $8911
map_control_0c8911:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
