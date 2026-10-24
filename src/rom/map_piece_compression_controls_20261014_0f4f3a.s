.setcpu "65816"
.segment "CODE"
.org $4F3A
map_control_0f4f3a:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
