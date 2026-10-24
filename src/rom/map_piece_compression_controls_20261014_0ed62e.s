.setcpu "65816"
.segment "CODE"
.org $D62E
map_control_0ed62e:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
