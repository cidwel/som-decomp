.setcpu "65816"
.segment "CODE"
.org $573E
map_control_0d573e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
