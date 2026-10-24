.setcpu "65816"
.segment "CODE"
.org $DCE9
map_control_0fdce9:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
