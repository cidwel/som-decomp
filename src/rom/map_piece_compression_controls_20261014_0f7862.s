.setcpu "65816"
.segment "CODE"
.org $7862
map_control_0f7862:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C9 ; same-value copy count/distance
