.setcpu "65816"
.segment "CODE"
.org $CCE3
map_control_0fcce3:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
