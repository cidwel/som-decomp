.setcpu "65816"
.segment "CODE"
.org $178C
map_control_0c178c:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
