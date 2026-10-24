.setcpu "65816"
.segment "CODE"
.org $D845
map_control_0fd845:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
