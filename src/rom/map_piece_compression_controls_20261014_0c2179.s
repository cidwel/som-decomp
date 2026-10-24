.setcpu "65816"
.segment "CODE"
.org $2179
map_control_0c2179:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
