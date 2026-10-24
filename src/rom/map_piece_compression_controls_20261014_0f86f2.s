.setcpu "65816"
.segment "CODE"
.org $86F2
map_control_0f86f2:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
