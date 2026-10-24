.setcpu "65816"
.segment "CODE"
.org $4999
map_control_0f4999:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
