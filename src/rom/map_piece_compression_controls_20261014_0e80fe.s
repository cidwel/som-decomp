.setcpu "65816"
.segment "CODE"
.org $80FE
map_control_0e80fe:
    .byte $E4 ; previous-row copy count
