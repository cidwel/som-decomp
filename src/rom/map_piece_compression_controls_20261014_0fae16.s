.setcpu "65816"
.segment "CODE"
.org $AE16
map_control_0fae16:
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
