.setcpu "65816"
.segment "CODE"
.org $7B6E
map_control_0d7b6e:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
