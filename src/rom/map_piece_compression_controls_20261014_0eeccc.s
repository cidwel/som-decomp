.setcpu "65816"
.segment "CODE"
.org $ECCC
map_control_0eeccc:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
    .byte $C6 ; same-value copy count/distance
