.setcpu "65816"
.segment "CODE"
.org $5CA2
map_control_0f5ca2:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
