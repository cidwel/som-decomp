.setcpu "65816"
.segment "CODE"
.org $F708
map_control_0ef708:
    .byte $E0 ; previous-row copy escape
    .byte $B7 ; row-distance/count
