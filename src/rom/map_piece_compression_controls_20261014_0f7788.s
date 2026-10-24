.setcpu "65816"
.segment "CODE"
.org $7788
map_control_0f7788:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
