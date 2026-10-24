.setcpu "65816"
.segment "CODE"
.org $C7EF
map_control_0dc7ef:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
