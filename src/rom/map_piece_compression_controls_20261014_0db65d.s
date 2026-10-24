.setcpu "65816"
.segment "CODE"
.org $B65D
map_control_0db65d:
    .byte $E3 ; previous-row copy count
