.setcpu "65816"
.segment "CODE"
.org $8B64
map_control_0c8b64:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
