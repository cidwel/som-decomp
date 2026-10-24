.setcpu "65816"
.segment "CODE"
.org $7724
map_control_0e7724:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E3 ; previous-row copy count
