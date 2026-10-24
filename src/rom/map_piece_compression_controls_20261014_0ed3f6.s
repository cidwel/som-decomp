.setcpu "65816"
.segment "CODE"
.org $D3F6
map_control_0ed3f6:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
