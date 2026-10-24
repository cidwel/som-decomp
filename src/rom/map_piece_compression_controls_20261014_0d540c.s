.setcpu "65816"
.segment "CODE"
.org $540C
map_control_0d540c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
