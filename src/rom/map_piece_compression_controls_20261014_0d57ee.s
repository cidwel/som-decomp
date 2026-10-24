.setcpu "65816"
.segment "CODE"
.org $57EE
map_control_0d57ee:
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
