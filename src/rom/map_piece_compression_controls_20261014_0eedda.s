.setcpu "65816"
.segment "CODE"
.org $EDDA
map_control_0eedda:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
