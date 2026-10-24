.setcpu "65816"
.segment "CODE"
.org $3C7E
map_control_0f3c7e:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
