.setcpu "65816"
.segment "CODE"
.org $7F9E
map_control_0f7f9e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
