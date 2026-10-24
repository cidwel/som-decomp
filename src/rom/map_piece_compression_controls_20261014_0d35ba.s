.setcpu "65816"
.segment "CODE"
.org $35BA
map_control_0d35ba:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
