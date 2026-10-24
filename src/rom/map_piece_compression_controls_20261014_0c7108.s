.setcpu "65816"
.segment "CODE"
.org $7108
map_control_0c7108:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
