.setcpu "65816"
.segment "CODE"
.org $ED0E
map_control_0ded0e:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
