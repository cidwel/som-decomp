.setcpu "65816"
.segment "CODE"
.org $B42C
map_control_0db42c:
    .byte $E7 ; previous-row copy count
