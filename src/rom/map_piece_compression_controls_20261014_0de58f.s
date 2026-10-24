.setcpu "65816"
.segment "CODE"
.org $E58F
map_control_0de58f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
