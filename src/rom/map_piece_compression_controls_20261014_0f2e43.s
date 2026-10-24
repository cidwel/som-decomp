.setcpu "65816"
.segment "CODE"
.org $2E43
map_control_0f2e43:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
