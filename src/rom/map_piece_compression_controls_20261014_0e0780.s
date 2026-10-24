.setcpu "65816"
.segment "CODE"
.org $0780
map_control_0e0780:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
