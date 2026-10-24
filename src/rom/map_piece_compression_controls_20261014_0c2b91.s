.setcpu "65816"
.segment "CODE"
.org $2B91
map_control_0c2b91:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
