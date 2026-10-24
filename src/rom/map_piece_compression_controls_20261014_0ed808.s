.setcpu "65816"
.segment "CODE"
.org $D808
map_control_0ed808:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
