.setcpu "65816"
.segment "CODE"
.org $B150
map_control_0fb150:
    .byte $E1 ; previous-row copy count
