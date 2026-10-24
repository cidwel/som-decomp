.setcpu "65816"
.segment "CODE"
.org $FCB1
map_control_0efcb1:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
