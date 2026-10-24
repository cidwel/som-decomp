.setcpu "65816"
.segment "CODE"
.org $549C
map_control_0d549c:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
