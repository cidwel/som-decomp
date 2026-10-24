.setcpu "65816"
.segment "CODE"
.org $173C
map_control_0c173c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
