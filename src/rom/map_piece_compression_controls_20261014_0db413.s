.setcpu "65816"
.segment "CODE"
.org $B413
map_control_0db413:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
