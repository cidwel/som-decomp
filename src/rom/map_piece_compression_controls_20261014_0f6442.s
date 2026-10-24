.setcpu "65816"
.segment "CODE"
.org $6442
map_control_0f6442:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
