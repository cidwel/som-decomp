.setcpu "65816"
.segment "CODE"
.org $FB91
map_control_0ffb91:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
