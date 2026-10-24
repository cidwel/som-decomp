.setcpu "65816"
.segment "CODE"
.org $B5FF
map_control_0eb5ff:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E1 ; previous-row copy count
