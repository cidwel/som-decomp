.setcpu "65816"
.segment "CODE"
.org $6DE8
map_control_0c6de8:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
