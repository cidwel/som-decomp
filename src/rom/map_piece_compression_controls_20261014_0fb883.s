.setcpu "65816"
.segment "CODE"
.org $B883
map_control_0fb883:
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
