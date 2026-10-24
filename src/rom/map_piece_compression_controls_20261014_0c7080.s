.setcpu "65816"
.segment "CODE"
.org $7080
map_control_0c7080:
    .byte $E1 ; previous-row copy count
