.setcpu "65816"
.segment "CODE"
.org $4839
map_control_0c4839:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
