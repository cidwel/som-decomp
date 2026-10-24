.setcpu "65816"
.segment "CODE"
.org $C924
map_control_0fc924:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
