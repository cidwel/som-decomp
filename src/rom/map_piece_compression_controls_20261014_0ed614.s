.setcpu "65816"
.segment "CODE"
.org $D614
map_control_0ed614:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
