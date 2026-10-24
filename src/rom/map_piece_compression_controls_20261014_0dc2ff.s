.setcpu "65816"
.segment "CODE"
.org $C2FF
map_control_0dc2ff:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
