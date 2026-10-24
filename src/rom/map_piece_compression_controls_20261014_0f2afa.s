.setcpu "65816"
.segment "CODE"
.org $2AFA
map_control_0f2afa:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E2 ; previous-row copy count
