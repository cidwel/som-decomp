.setcpu "65816"
.segment "CODE"
.org $3B0D
map_control_0c3b0d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
