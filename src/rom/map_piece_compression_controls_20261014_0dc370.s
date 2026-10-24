.setcpu "65816"
.segment "CODE"
.org $C370
map_control_0dc370:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
