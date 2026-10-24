.setcpu "65816"
.segment "CODE"
.org $F492
map_control_0ff492:
    .byte $E1 ; previous-row copy count
