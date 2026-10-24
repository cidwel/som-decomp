.setcpu "65816"
.segment "CODE"
.org $E0DA
map_control_0de0da:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
