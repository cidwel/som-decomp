.setcpu "65816"
.segment "CODE"
.org $45AA
map_control_0e45aa:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
