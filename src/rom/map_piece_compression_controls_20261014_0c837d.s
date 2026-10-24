.setcpu "65816"
.segment "CODE"
.org $837D
map_control_0c837d:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7A ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
