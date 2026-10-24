.setcpu "65816"
.segment "CODE"
.org $B8D9
map_control_0fb8d9:
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
