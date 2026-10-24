.setcpu "65816"
.segment "CODE"
.org $DE3E
map_control_0dde3e:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
