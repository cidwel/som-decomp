.setcpu "65816"
.segment "CODE"
.org $2BA3
map_control_0f2ba3:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
