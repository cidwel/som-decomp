.setcpu "65816"
.segment "CODE"
.org $0254
map_control_0e0254:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $78 ; row-distance/count
