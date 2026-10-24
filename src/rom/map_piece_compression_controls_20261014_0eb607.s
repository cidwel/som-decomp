.setcpu "65816"
.segment "CODE"
.org $B607
map_control_0eb607:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
