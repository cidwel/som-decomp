.setcpu "65816"
.segment "CODE"
.org $2187
map_control_0d2187:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
