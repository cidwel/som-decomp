.setcpu "65816"
.segment "CODE"
.org $616E
map_control_0f616e:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
