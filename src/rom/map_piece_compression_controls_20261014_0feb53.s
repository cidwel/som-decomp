.setcpu "65816"
.segment "CODE"
.org $EB53
map_control_0feb53:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
