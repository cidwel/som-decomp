.setcpu "65816"
.segment "CODE"
.org $4D37
map_control_0f4d37:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
