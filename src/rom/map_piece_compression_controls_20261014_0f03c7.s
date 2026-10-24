.setcpu "65816"
.segment "CODE"
.org $03C7
map_control_0f03c7:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
