.setcpu "65816"
.segment "CODE"
.org $F013
map_control_0ff013:
    .byte $E1 ; previous-row copy count
