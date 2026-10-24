.setcpu "65816"
.segment "CODE"
.org $6E68
map_control_0c6e68:
    .byte $F3 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
