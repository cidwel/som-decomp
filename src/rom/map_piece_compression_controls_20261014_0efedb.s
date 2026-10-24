.setcpu "65816"
.segment "CODE"
.org $FEDB
map_control_0efedb:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
