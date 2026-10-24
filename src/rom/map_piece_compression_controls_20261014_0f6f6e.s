.setcpu "65816"
.segment "CODE"
.org $6F6E
map_control_0f6f6e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
