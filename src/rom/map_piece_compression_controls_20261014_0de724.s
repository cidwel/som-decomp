.setcpu "65816"
.segment "CODE"
.org $E724
map_control_0de724:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
