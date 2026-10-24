.setcpu "65816"
.segment "CODE"
.org $E8E1
map_control_0de8e1:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
