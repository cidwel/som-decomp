.setcpu "65816"
.segment "CODE"
.org $6A87
map_control_0d6a87:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
