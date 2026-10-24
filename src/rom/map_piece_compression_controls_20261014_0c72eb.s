.setcpu "65816"
.segment "CODE"
.org $72EB
map_control_0c72eb:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
