.setcpu "65816"
.segment "CODE"
.org $F876
map_control_0ff876:
    .byte $E2 ; previous-row copy count
