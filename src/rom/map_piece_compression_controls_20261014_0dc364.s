.setcpu "65816"
.segment "CODE"
.org $C364
map_control_0dc364:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
