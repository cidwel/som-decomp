.setcpu "65816"
.segment "CODE"
.org $7B7D
map_control_0d7b7d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
