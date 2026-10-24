.setcpu "65816"
.segment "CODE"
.org $59F5
map_control_0e59f5:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
