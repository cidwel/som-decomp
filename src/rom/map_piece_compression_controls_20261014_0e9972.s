.setcpu "65816"
.segment "CODE"
.org $9972
map_control_0e9972:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
