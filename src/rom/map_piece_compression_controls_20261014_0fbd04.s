.setcpu "65816"
.segment "CODE"
.org $BD04
map_control_0fbd04:
    .byte $E5 ; previous-row copy count
