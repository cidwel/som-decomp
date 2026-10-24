.setcpu "65816"
.segment "CODE"
.org $C80C
map_control_0dc80c:
    .byte $E1 ; previous-row copy count
