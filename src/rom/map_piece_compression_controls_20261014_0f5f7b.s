.setcpu "65816"
.segment "CODE"
.org $5F7B
map_control_0f5f7b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
