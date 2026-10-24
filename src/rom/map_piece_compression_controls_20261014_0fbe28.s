.setcpu "65816"
.segment "CODE"
.org $BE28
map_control_0fbe28:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
