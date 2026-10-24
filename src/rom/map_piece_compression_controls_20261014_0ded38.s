.setcpu "65816"
.segment "CODE"
.org $ED38
map_control_0ded38:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
