.setcpu "65816"
.segment "CODE"
.org $CEDD
map_control_0dcedd:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
