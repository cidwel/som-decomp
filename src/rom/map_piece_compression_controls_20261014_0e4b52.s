.setcpu "65816"
.segment "CODE"
.org $4B52
map_control_0e4b52:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
