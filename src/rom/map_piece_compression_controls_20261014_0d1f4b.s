.setcpu "65816"
.segment "CODE"
.org $1F4B
map_control_0d1f4b:
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
