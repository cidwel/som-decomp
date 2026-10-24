.setcpu "65816"
.segment "CODE"
.org $7F8E
map_control_0f7f8e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
