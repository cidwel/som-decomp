.setcpu "65816"
.segment "CODE"
.org $5010
map_control_0e5010:
    .byte $E3 ; previous-row copy count
