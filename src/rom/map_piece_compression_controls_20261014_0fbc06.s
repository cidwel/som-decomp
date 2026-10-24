.setcpu "65816"
.segment "CODE"
.org $BC06
map_control_0fbc06:
    .byte $C6 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
