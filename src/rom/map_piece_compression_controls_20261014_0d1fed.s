.setcpu "65816"
.segment "CODE"
.org $1FED
map_control_0d1fed:
    .byte $E1 ; previous-row copy count
