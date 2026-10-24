.setcpu "65816"
.segment "CODE"
.org $4647
map_control_0f4647:
    .byte $E0 ; previous-row copy escape
    .byte $5C ; row-distance/count
    .byte $C4 ; same-value copy count/distance
