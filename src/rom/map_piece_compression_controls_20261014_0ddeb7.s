.setcpu "65816"
.segment "CODE"
.org $DEB7
map_control_0ddeb7:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
