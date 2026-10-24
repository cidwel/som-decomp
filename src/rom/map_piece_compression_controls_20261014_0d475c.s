.setcpu "65816"
.segment "CODE"
.org $475C
map_control_0d475c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
