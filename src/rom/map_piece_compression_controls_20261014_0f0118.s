.setcpu "65816"
.segment "CODE"
.org $0118
map_control_0f0118:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
    .byte $E2 ; previous-row copy count
