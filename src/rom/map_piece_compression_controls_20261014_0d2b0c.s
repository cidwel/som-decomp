.setcpu "65816"
.segment "CODE"
.org $2B0C
map_control_0d2b0c:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
