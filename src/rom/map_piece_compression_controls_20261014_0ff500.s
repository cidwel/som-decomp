.setcpu "65816"
.segment "CODE"
.org $F500
map_control_0ff500:
    .byte $E1 ; previous-row copy count
