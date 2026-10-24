.setcpu "65816"
.segment "CODE"
.org $FC3E
map_control_0ffc3e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
