.setcpu "65816"
.segment "CODE"
.org $24FF
map_control_0c24ff:
    .byte $E1 ; previous-row copy count
