.setcpu "65816"
.segment "CODE"
.org $9615
map_control_0d9615:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
