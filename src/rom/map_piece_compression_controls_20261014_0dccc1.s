.setcpu "65816"
.segment "CODE"
.org $CCC1
map_control_0dccc1:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
