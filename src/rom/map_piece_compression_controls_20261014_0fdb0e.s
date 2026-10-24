.setcpu "65816"
.segment "CODE"
.org $DB0E
map_control_0fdb0e:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
