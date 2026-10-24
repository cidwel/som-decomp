.setcpu "65816"
.segment "CODE"
.org $6085
map_control_0f6085:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
