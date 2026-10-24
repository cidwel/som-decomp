.setcpu "65816"
.segment "CODE"
.org $AEE7
map_control_0daee7:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
