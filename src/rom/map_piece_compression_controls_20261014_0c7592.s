.setcpu "65816"
.segment "CODE"
.org $7592
map_control_0c7592:
    .byte $D7 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
