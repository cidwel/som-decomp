.setcpu "65816"
.segment "CODE"
.org $5C39
map_control_0f5c39:
    .byte $EC ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
