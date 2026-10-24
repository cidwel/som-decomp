.setcpu "65816"
.segment "CODE"
.org $B616
map_control_0db616:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
