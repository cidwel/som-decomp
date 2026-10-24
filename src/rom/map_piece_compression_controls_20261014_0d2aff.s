.setcpu "65816"
.segment "CODE"
.org $2AFF
map_control_0d2aff:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
