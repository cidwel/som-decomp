.setcpu "65816"
.segment "CODE"
.org $16D5
map_control_0c16d5:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
