.setcpu "65816"
.segment "CODE"
.org $F4B5
map_control_0ef4b5:
    .byte $E0 ; previous-row copy escape
    .byte $FB ; row-distance/count
    .byte $CA ; same-value copy count/distance
