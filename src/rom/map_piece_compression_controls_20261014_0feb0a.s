.setcpu "65816"
.segment "CODE"
.org $EB0A
map_control_0feb0a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
