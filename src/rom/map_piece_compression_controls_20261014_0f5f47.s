.setcpu "65816"
.segment "CODE"
.org $5F47
map_control_0f5f47:
    .byte $E5 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
