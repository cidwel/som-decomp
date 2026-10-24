.setcpu "65816"
.segment "CODE"
.org $E5F7
map_control_0de5f7:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
