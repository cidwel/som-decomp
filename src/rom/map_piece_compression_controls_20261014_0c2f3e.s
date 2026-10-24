.setcpu "65816"
.segment "CODE"
.org $2F3E
map_control_0c2f3e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
