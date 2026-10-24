.setcpu "65816"
.segment "CODE"
.org $672E
map_control_0d672e:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
