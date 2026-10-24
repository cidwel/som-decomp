.setcpu "65816"
.segment "CODE"
.org $F87B
map_control_0ff87b:
    .byte $E6 ; previous-row copy count
