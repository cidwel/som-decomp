.setcpu "65816"
.segment "CODE"
.org $D93E
map_control_0fd93e:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
