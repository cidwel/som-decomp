.setcpu "65816"
.segment "CODE"
.org $B80E
map_control_0db80e:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
