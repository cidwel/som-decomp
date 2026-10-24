.setcpu "65816"
.segment "CODE"
.org $61A0
map_control_0c61a0:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
