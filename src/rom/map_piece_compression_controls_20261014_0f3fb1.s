.setcpu "65816"
.segment "CODE"
.org $3FB1
map_control_0f3fb1:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
