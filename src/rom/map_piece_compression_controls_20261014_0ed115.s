.setcpu "65816"
.segment "CODE"
.org $D115
map_control_0ed115:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
