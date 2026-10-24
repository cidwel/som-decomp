.setcpu "65816"
.segment "CODE"
.org $AD99
map_control_0fad99:
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
