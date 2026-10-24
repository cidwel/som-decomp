.setcpu "65816"
.segment "CODE"
.org $7F8B
map_control_0d7f8b:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
