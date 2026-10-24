.setcpu "65816"
.segment "CODE"
.org $DE3E
map_control_0fde3e:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
