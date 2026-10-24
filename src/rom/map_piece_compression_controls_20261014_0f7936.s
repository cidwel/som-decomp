.setcpu "65816"
.segment "CODE"
.org $7936
map_control_0f7936:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
