.setcpu "65816"
.segment "CODE"
.org $2FB3
map_control_0e2fb3:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
