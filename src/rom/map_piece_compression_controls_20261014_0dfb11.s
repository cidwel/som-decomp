.setcpu "65816"
.segment "CODE"
.org $FB11
map_control_0dfb11:
    .byte $E2 ; previous-row copy count
