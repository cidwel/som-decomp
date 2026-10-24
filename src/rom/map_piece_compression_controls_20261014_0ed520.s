.setcpu "65816"
.segment "CODE"
.org $D520
map_control_0ed520:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
