.setcpu "65816"
.segment "CODE"
.org $77E0
map_control_0f77e0:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
