.setcpu "65816"
.segment "CODE"
.org $EBED
map_control_0febed:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
