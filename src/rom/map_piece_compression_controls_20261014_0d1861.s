.setcpu "65816"
.segment "CODE"
.org $1861
map_control_0d1861:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
