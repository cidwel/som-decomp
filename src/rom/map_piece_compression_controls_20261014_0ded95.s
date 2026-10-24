.setcpu "65816"
.segment "CODE"
.org $ED95
map_control_0ded95:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
