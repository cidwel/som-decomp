.setcpu "65816"
.segment "CODE"
.org $929E
map_control_0f929e:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
