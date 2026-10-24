.setcpu "65816"
.segment "CODE"
.org $72F7
map_control_0e72f7:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
