.setcpu "65816"
.segment "CODE"
.org $D153
map_control_0dd153:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
