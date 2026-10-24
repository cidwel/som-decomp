.setcpu "65816"
.segment "CODE"
.org $93CE
map_control_0d93ce:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
