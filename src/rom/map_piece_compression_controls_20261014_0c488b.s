.setcpu "65816"
.segment "CODE"
.org $488B
map_control_0c488b:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
