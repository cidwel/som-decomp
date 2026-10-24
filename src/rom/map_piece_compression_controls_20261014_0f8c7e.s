.setcpu "65816"
.segment "CODE"
.org $8C7E
map_control_0f8c7e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
