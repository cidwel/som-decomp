.setcpu "65816"
.segment "CODE"
.org $1E06
map_control_0f1e06:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
