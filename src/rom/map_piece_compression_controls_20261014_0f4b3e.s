.setcpu "65816"
.segment "CODE"
.org $4B3E
map_control_0f4b3e:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
