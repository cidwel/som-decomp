.setcpu "65816"
.segment "CODE"
.org $9805
map_control_0f9805:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
