.setcpu "65816"
.segment "CODE"
.org $B113
map_control_0eb113:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
