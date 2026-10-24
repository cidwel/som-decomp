.setcpu "65816"
.segment "CODE"
.org $A60D
map_control_0da60d:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
