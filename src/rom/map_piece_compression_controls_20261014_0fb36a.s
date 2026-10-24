.setcpu "65816"
.segment "CODE"
.org $B36A
map_control_0fb36a:
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
