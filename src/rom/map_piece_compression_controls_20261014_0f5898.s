.setcpu "65816"
.segment "CODE"
.org $5898
map_control_0f5898:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
