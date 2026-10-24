.setcpu "65816"
.segment "CODE"
.org $B00A
map_control_0fb00a:
    .byte $E4 ; previous-row copy count
