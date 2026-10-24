.setcpu "65816"
.segment "CODE"
.org $BDB7
map_control_0fbdb7:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
