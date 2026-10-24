.setcpu "65816"
.segment "CODE"
.org $B025
map_control_0eb025:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
