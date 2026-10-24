.setcpu "65816"
.segment "CODE"
.org $8B02
map_control_0f8b02:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5D ; row-distance/count
