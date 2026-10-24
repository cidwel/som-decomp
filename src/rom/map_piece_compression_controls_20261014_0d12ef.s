.setcpu "65816"
.segment "CODE"
.org $12EF
map_control_0d12ef:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
