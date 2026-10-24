.setcpu "65816"
.segment "CODE"
.org $148C
map_control_0c148c:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $D3 ; row-distance/count
