.setcpu "65816"
.segment "CODE"
.org $71DA
map_control_0f71da:
    .byte $E1 ; previous-row copy count
