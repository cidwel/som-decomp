.setcpu "65816"
.segment "CODE"
.org $6100
map_control_0d6100:
    .byte $E1 ; previous-row copy count
