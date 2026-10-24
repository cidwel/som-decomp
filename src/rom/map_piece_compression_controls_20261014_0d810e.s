.setcpu "65816"
.segment "CODE"
.org $810E
map_control_0d810e:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
