.setcpu "65816"
.segment "CODE"
.org $55B2
map_control_0d55b2:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
