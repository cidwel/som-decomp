.setcpu "65816"
.segment "CODE"
.org $F2AF
map_control_0ef2af:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
