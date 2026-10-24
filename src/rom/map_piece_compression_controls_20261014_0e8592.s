.setcpu "65816"
.segment "CODE"
.org $8592
map_control_0e8592:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
