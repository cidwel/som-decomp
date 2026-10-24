.setcpu "65816"
.segment "CODE"
.org $B3F4
map_control_0db3f4:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
