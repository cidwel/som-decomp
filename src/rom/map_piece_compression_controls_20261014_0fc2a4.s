.setcpu "65816"
.segment "CODE"
.org $C2A4
map_control_0fc2a4:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $64 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2B ; distance low bit/count
    .byte $E3 ; previous-row copy count
