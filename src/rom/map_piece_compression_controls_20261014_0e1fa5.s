.setcpu "65816"
.segment "CODE"
.org $1FA5
map_control_0e1fa5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
