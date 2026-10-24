.setcpu "65816"
.segment "CODE"
.org $4E39
map_control_0f4e39:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
