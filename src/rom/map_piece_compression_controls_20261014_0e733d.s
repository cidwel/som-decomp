.setcpu "65816"
.segment "CODE"
.org $733D
map_control_0e733d:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
