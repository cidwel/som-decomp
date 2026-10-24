.setcpu "65816"
.segment "CODE"
.org $1747
map_control_0c1747:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
