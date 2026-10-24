.setcpu "65816"
.segment "CODE"
.org $ACC1
map_control_0dacc1:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
