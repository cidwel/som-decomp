.setcpu "65816"
.segment "CODE"
.org $C3CA
map_control_0dc3ca:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
