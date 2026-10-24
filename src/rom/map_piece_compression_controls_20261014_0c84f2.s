.setcpu "65816"
.segment "CODE"
.org $84F2
map_control_0c84f2:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
