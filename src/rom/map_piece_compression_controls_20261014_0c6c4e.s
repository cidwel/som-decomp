.setcpu "65816"
.segment "CODE"
.org $6C4E
map_control_0c6c4e:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
