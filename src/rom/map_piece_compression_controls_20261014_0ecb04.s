.setcpu "65816"
.segment "CODE"
.org $CB04
map_control_0ecb04:
    .byte $E4 ; previous-row copy count
