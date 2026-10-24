.setcpu "65816"
.segment "CODE"
.org $EF20
map_control_0eef20:
    .byte $E2 ; previous-row copy count
