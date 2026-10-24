.setcpu "65816"
.segment "CODE"
.org $906E
map_control_0e906e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
