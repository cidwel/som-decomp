.setcpu "65816"
.segment "CODE"
.org $6514
map_control_0f6514:
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
