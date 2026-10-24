.setcpu "65816"
.segment "CODE"
.org $57E1
map_control_0d57e1:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $DF ; same-value copy count/distance
