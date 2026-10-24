.setcpu "65816"
.segment "CODE"
.org $4A87
map_control_0d4a87:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
