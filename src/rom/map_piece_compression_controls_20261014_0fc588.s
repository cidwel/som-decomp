.setcpu "65816"
.segment "CODE"
.org $C588
map_control_0fc588:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
