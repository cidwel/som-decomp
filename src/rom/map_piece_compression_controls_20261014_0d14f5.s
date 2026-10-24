.setcpu "65816"
.segment "CODE"
.org $14F5
map_control_0d14f5:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
