.setcpu "65816"
.segment "CODE"
.org $56C5
map_control_0d56c5:
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
