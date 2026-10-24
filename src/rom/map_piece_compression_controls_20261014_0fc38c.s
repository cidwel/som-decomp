.setcpu "65816"
.segment "CODE"
.org $C38C
map_control_0fc38c:
    .byte $E0 ; previous-row copy escape
    .byte $AA ; row-distance/count
