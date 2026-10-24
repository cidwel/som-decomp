.setcpu "65816"
.segment "CODE"
.org $63E6
map_control_0e63e6:
    .byte $C1 ; same-value copy count/distance
    .byte $F2 ; progressive-copy count
    .byte $E1 ; previous-row copy count
