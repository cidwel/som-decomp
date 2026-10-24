.setcpu "65816"
.segment "CODE"
.org $F916
map_control_0ff916:
    .byte $E2 ; previous-row copy count
