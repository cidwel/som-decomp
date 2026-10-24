.setcpu "65816"
.segment "CODE"
.org $6D87
map_control_0c6d87:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
