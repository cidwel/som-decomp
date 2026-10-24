.setcpu "65816"
.segment "CODE"
.org $3925
map_control_0f3925:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
