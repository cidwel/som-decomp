.setcpu "65816"
.segment "CODE"
.org $F28D
map_control_0ef28d:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
