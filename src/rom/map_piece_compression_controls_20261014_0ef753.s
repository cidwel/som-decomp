.setcpu "65816"
.segment "CODE"
.org $F753
map_control_0ef753:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
