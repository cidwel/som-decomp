.setcpu "65816"
.segment "CODE"
.org $D705
map_control_0ed705:
    .byte $E5 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
