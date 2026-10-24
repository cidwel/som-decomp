.setcpu "65816"
.segment "CODE"
.org $ED28
map_control_0ded28:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
