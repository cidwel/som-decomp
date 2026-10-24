.setcpu "65816"
.segment "CODE"
.org $2B5A
map_control_0f2b5a:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
