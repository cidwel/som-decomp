.setcpu "65816"
.segment "CODE"
.org $0D79
map_control_0d0d79:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
