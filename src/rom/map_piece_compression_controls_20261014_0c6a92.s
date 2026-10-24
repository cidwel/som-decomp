.setcpu "65816"
.segment "CODE"
.org $6A92
map_control_0c6a92:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
