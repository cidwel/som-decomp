.setcpu "65816"
.segment "CODE"
.org $1C15
map_control_0e1c15:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
