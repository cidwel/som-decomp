.setcpu "65816"
.segment "CODE"
.org $003E
map_control_0f003e:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $C9 ; same-value copy count/distance
