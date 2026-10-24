.setcpu "65816"
.segment "CODE"
.org $2898
map_control_0e2898:
    .byte $E0 ; previous-row copy escape
    .byte $66 ; row-distance/count
