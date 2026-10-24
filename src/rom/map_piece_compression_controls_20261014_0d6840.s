.setcpu "65816"
.segment "CODE"
.org $6840
map_control_0d6840:
    .byte $DA ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
