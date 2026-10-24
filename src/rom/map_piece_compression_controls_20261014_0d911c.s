.setcpu "65816"
.segment "CODE"
.org $911C
map_control_0d911c:
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
