.setcpu "65816"
.segment "CODE"
.org $EF0E
map_control_0def0e:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
