.setcpu "65816"
.segment "CODE"
.org $F828
map_control_0ff828:
    .byte $E6 ; previous-row copy count
