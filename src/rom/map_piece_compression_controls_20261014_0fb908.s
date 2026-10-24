.setcpu "65816"
.segment "CODE"
.org $B908
map_control_0fb908:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $31 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
