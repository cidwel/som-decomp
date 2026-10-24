.setcpu "65816"
.segment "CODE"
.org $89C2
map_control_0f89c2:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
