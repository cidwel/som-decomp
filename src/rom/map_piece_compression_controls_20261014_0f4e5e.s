.setcpu "65816"
.segment "CODE"
.org $4E5E
map_control_0f4e5e:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
