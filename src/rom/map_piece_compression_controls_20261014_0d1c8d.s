.setcpu "65816"
.segment "CODE"
.org $1C8D
map_control_0d1c8d:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
