.setcpu "65816"
.segment "CODE"
.org $AA6E
map_control_0eaa6e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
