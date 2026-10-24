.setcpu "65816"
.segment "CODE"
.org $6D9B
map_control_0c6d9b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
