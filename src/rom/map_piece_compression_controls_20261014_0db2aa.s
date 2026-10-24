.setcpu "65816"
.segment "CODE"
.org $B2AA
map_control_0db2aa:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
