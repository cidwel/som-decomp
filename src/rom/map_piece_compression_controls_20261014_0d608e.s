.setcpu "65816"
.segment "CODE"
.org $608E
map_control_0d608e:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
