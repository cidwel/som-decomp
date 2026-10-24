.setcpu "65816"
.segment "CODE"
.org $F19C
map_control_0cf19c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
