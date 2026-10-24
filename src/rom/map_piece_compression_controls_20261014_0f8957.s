.setcpu "65816"
.segment "CODE"
.org $8957
map_control_0f8957:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
