.setcpu "65816"
.segment "CODE"
.org $8C9D
map_control_0f8c9d:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
