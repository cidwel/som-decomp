.setcpu "65816"
.segment "CODE"
.org $61C9
map_control_0d61c9:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
