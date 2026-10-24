.setcpu "65816"
.segment "CODE"
.org $F525
map_control_0ff525:
    .byte $E1 ; previous-row copy count
