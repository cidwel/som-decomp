.setcpu "65816"
.segment "CODE"
.org $AD8E
map_control_0dad8e:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
