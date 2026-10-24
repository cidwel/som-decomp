.setcpu "65816"
.segment "CODE"
.org $54D7
map_control_0f54d7:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
