.setcpu "65816"
.segment "CODE"
.org $13F3
map_control_0c13f3:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
