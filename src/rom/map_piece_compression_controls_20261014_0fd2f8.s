.setcpu "65816"
.segment "CODE"
.org $D2F8
map_control_0fd2f8:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
