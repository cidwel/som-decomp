.setcpu "65816"
.segment "CODE"
.org $66B1
map_control_0d66b1:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
