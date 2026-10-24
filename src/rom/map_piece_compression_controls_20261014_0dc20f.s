.setcpu "65816"
.segment "CODE"
.org $C20F
map_control_0dc20f:
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
