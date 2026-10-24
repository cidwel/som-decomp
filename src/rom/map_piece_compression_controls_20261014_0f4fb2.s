.setcpu "65816"
.segment "CODE"
.org $4FB2
map_control_0f4fb2:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
