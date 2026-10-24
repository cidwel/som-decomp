.setcpu "65816"
.segment "CODE"
.org $C3E5
map_control_0fc3e5:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4C ; row-distance/count
