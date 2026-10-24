.setcpu "65816"
.segment "CODE"
.org $406E
map_control_0c406e:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
