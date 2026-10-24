.setcpu "65816"
.segment "CODE"
.org $734A
map_control_0c734a:
    .byte $CA ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
