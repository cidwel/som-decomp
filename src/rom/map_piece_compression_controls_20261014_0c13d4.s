.setcpu "65816"
.segment "CODE"
.org $13D4
map_control_0c13d4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $33 ; distance low bit/count
