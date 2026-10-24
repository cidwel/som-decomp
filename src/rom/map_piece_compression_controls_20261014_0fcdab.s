.setcpu "65816"
.segment "CODE"
.org $CDAB
map_control_0fcdab:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
