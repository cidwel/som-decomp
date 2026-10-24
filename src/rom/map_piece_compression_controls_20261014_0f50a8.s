.setcpu "65816"
.segment "CODE"
.org $50A8
map_control_0f50a8:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
