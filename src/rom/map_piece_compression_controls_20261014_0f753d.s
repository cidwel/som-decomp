.setcpu "65816"
.segment "CODE"
.org $753D
map_control_0f753d:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
    .byte $C1 ; same-value copy count/distance
