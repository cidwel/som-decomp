.setcpu "65816"
.segment "CODE"
.org $8FD7
map_control_0d8fd7:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
