.setcpu "65816"
.segment "CODE"
.org $66D6
map_control_0f66d6:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
