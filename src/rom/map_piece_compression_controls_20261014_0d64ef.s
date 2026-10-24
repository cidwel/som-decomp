.setcpu "65816"
.segment "CODE"
.org $64EF
map_control_0d64ef:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
