.setcpu "65816"
.segment "CODE"
.org $7557
map_control_0f7557:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $E2 ; previous-row copy count
