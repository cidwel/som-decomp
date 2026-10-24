.setcpu "65816"
.segment "CODE"
.org $D5F6
map_control_0ed5f6:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
