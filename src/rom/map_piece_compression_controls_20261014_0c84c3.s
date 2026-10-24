.setcpu "65816"
.segment "CODE"
.org $84C3
map_control_0c84c3:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
