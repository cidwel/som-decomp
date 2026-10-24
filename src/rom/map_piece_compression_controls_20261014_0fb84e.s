.setcpu "65816"
.segment "CODE"
.org $B84E
map_control_0fb84e:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
