.setcpu "65816"
.segment "CODE"
.org $D5AE
map_control_0fd5ae:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
