.setcpu "65816"
.segment "CODE"
.org $C8F6
map_control_0fc8f6:
    .byte $ED ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
