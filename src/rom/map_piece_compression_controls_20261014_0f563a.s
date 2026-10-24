.setcpu "65816"
.segment "CODE"
.org $563A
map_control_0f563a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
