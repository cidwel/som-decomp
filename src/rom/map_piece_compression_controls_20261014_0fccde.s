.setcpu "65816"
.segment "CODE"
.org $CCDE
map_control_0fccde:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
