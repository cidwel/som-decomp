.setcpu "65816"
.segment "CODE"
.org $C412
map_control_0dc412:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
