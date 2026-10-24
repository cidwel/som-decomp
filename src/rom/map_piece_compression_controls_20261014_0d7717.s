.setcpu "65816"
.segment "CODE"
.org $7717
map_control_0d7717:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
