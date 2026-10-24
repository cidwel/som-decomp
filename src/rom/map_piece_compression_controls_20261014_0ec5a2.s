.setcpu "65816"
.segment "CODE"
.org $C5A2
map_control_0ec5a2:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
