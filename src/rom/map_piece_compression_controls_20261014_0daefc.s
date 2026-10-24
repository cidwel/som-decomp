.setcpu "65816"
.segment "CODE"
.org $AEFC
map_control_0daefc:
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $C7 ; same-value copy count/distance
