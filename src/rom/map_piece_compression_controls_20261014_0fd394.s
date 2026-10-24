.setcpu "65816"
.segment "CODE"
.org $D394
map_control_0fd394:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
