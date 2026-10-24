.setcpu "65816"
.segment "CODE"
.org $B174
map_control_0db174:
    .byte $E1 ; previous-row copy count
