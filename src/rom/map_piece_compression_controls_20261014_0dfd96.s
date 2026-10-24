.setcpu "65816"
.segment "CODE"
.org $FD96
map_control_0dfd96:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
