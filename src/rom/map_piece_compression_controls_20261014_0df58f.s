.setcpu "65816"
.segment "CODE"
.org $F58F
map_control_0df58f:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
