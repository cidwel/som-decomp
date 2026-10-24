.setcpu "65816"
.segment "CODE"
.org $9C9E
map_control_0f9c9e:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
