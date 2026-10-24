.setcpu "65816"
.segment "CODE"
.org $5FF1
map_control_0f5ff1:
    .byte $E4 ; previous-row copy count
