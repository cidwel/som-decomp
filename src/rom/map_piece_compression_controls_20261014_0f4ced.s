.setcpu "65816"
.segment "CODE"
.org $4CED
map_control_0f4ced:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
