.setcpu "65816"
.segment "CODE"
.org $CDB4
map_control_0ecdb4:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
